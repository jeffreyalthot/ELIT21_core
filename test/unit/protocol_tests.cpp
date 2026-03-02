#include "protocol.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

bool Expect(const bool condition, const std::string& message)
{
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
        return false;
    }
    return true;
}

} // namespace

int main()
{
    bool ok = true;

    const auto header = elit21::protocol::BuildMessageHeader(elit21::protocol::MAINNET_MAGIC, "version", 42, 1234);
    ok &= Expect(header.CommandName() == "version", "extract command name");
    ok &= Expect(header.IsValid(), "header with known command is valid");

    auto invalid = header;
    invalid.command[0] = '\0';
    ok &= Expect(!invalid.IsValid(), "empty command is rejected");

    auto oversized = header;
    oversized.payload_size = (32U * 1024U * 1024U) + 1U;
    ok &= Expect(!oversized.IsValid(), "oversized payload is rejected");

    auto malformed = header;
    malformed.command[8] = 'x';
    ok &= Expect(!malformed.IsValid(), "bytes after null terminator are rejected");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
