#include "protocol.h"

#include <algorithm>

namespace elit21::protocol {

std::string MessageHeader::CommandName() const
{
    auto end_it = std::find(command.cbegin(), command.cend(), '\0');
    return std::string(command.cbegin(), end_it);
}

bool MessageHeader::IsValid() const
{
    if (payload_size > (32U * 1024U * 1024U)) {
        return false;
    }

    bool seen_null = false;
    for (char c : command) {
        if (c == '\0') {
            seen_null = true;
            continue;
        }

        if (seen_null) {
            return false;
        }

        if (static_cast<unsigned char>(c) < 0x20U || static_cast<unsigned char>(c) > 0x7EU) {
            return false;
        }
    }

    return !CommandName().empty();
}

MessageHeader BuildMessageHeader(const std::uint32_t magic, const std::string& command,
                                 const std::uint32_t payload_size, const std::uint32_t checksum)
{
    MessageHeader header;
    header.magic = magic;
    header.payload_size = payload_size;
    header.checksum = checksum;

    const std::size_t to_copy = std::min(command.size(), COMMAND_SIZE);
    std::copy_n(command.cbegin(), to_copy, header.command.begin());

    return header;
}

} // namespace elit21::protocol
