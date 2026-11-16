// Unit tests for the WebSocket core of the browser bridge. The code under test
// is the region between "BRIDGE-CORE-BEGIN" and "BRIDGE-CORE-END" in
// mac-dock-26320.wh.cpp, extracted by tools/test-bridge-core.ps1.
#include <windows.h>
#include <bcrypt.h>

#include <cstdio>
#include <cstring>
#include <string>

#include "bridge_core.inc"

static int g_failures = 0;
#define CHECK(cond)                                                   \
    do {                                                              \
        if (!(cond)) {                                                \
            std::printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
            g_failures++;                                             \
        }                                                             \
    } while (0)

static std::string Bytes(std::initializer_list<int> list) {
    std::string out;
    for (int b : list) {
        out.push_back((char)b);
    }
    return out;
}

// A masked client frame (mask 0x37 0xfa 0x21 0x3d).
static std::string Masked(int first, const std::string& payload) {
    const unsigned char mask[4] = {0x37, 0xfa, 0x21, 0x3d};
    std::string out;
    out.push_back((char)first);
    if (payload.size() < 126) {
        out.push_back((char)(0x80 | payload.size()));
    } else {
        out.push_back((char)(0x80 | 126));
        out.push_back((char)(payload.size() >> 8));
        out.push_back((char)(payload.size() & 0xff));
    }
    out.append((const char*)mask, 4);
    for (size_t i = 0; i < payload.size(); i++) {
        out.push_back((char)(payload[i] ^ mask[i % 4]));
    }
    return out;
}

static void TestAcceptKey() {
    // RFC 6455, section 1.3.
    CHECK(WsAcceptKey("dGhlIHNhbXBsZSBub25jZQ==") ==
          "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=");
}

static void TestHeaderValue() {
    const std::string request =
        "GET / HTTP/1.1\r\nHost: 127.0.0.1:47821\r\nsec-websocket-key:  abc== "
        "\r\nOrigin: chrome-extension://xyz\r\n\r\n";
    CHECK(HttpHeaderValue(request, "Sec-WebSocket-Key") == "abc==");
    CHECK(HttpHeaderValue(request, "origin") == "chrome-extension://xyz");
    CHECK(HttpHeaderValue(request, "Upgrade").empty());
}

static void TestOrigin() {
    CHECK(BridgeOriginAllowed("chrome-extension://abcdef"));
    CHECK(BridgeOriginAllowed("moz-extension://1234-5678"));
    CHECK(!BridgeOriginAllowed("https://example.com"));
    CHECK(!BridgeOriginAllowed("null"));
    CHECK(!BridgeOriginAllowed(""));
    CHECK(!BridgeOriginAllowed("https://chrome-extension://evil"));
}

static void TestMaskedHello() {
    WsReader reader;
    // RFC 6455, section 5.7: a single-frame masked text message "Hello".
    reader.Feed(Bytes({0x81, 0x85, 0x37, 0xfa, 0x21, 0x3d, 0x7f, 0x9f, 0x4d,
                       0x51, 0x58}));
    WsMessage message;
    CHECK(reader.Next(&message) == WsResult::Message);
    CHECK(message.opcode == 1);
    CHECK(message.payload == "Hello");
    CHECK(reader.Next(&message) == WsResult::NeedMore);
}

static void TestByteByByte() {
    WsReader reader;
    const std::string frame = Masked(0x81, "{\"type\":\"ping\"}");
    WsMessage message;
    for (size_t i = 0; i + 1 < frame.size(); i++) {
        reader.Feed(frame.substr(i, 1));
        CHECK(reader.Next(&message) == WsResult::NeedMore);
    }
    reader.Feed(frame.substr(frame.size() - 1));
    CHECK(reader.Next(&message) == WsResult::Message);
    CHECK(message.payload == "{\"type\":\"ping\"}");
}

static void TestFragmentsWithPingInBetween() {
    WsReader reader;
    reader.Feed(Masked(0x01, "Hel"));   // text, not final
    reader.Feed(Masked(0x89, "p"));     // ping (control, final)
    reader.Feed(Masked(0x80, "lo"));    // continuation, final
    WsMessage message;
    CHECK(reader.Next(&message) == WsResult::Message);
    CHECK(message.opcode == 9);
    CHECK(message.payload == "p");
    CHECK(reader.Next(&message) == WsResult::Message);
    CHECK(message.opcode == 1);
    CHECK(message.payload == "Hello");
}

static void TestExtendedLength() {
    WsReader reader;
    const std::string big(300, 'x');
    reader.Feed(Masked(0x81, big));
    WsMessage message;
    CHECK(reader.Next(&message) == WsResult::Message);
    CHECK(message.payload == big);
}

static void TestUnmaskedRejected() {
    WsReader reader;
    reader.Feed(Bytes({0x81, 0x02, 'h', 'i'}));
    WsMessage message;
    CHECK(reader.Next(&message) == WsResult::Error);
}

static void TestTooBig() {
    WsReader reader;
    // 64-bit length of 2 MB, masked.
    reader.Feed(Bytes({0x81, 0xFF, 0, 0, 0, 0, 0, 0x20, 0, 0, 1, 2, 3, 4}));
    WsMessage message;
    CHECK(reader.Next(&message) == WsResult::Error);
}

static void TestEncode() {
    CHECK(WsEncode(1, "hi") == Bytes({0x81, 0x02, 'h', 'i'}));
    const std::string frame = WsEncode(1, std::string(200, 'a'));
    CHECK(frame.size() == 4 + 200);
    CHECK((unsigned char)frame[1] == 0x7E);
    CHECK((unsigned char)frame[2] == 0x00);
    CHECK((unsigned char)frame[3] == 0xC8);
    CHECK(WsEncode(10, "p") == Bytes({0x8A, 0x01, 'p'}));
}

int main() {
    TestAcceptKey();
    TestHeaderValue();
    TestOrigin();
    TestMaskedHello();
    TestByteByByte();
    TestFragmentsWithPingInBetween();
    TestExtendedLength();
    TestUnmaskedRejected();
    TestTooBig();
    TestEncode();
    if (g_failures) {
        std::printf("%d failure(s)\n", g_failures);
        return 1;
    }
    std::printf("all bridge core tests passed\n");
    return 0;
}
