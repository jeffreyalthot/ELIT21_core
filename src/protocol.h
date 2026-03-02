#ifndef ELIT21_PROTOCOL_H
#define ELIT21_PROTOCOL_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>

namespace elit21::protocol {

inline constexpr std::size_t COMMAND_SIZE = 12;
inline constexpr std::uint32_t MAINNET_MAGIC = 0xe121c0de;
inline constexpr std::uint32_t TESTNET_MAGIC = 0x0b110907;

struct MessageHeader {
    std::uint32_t magic{MAINNET_MAGIC};
    std::array<char, COMMAND_SIZE> command{};
    std::uint32_t payload_size{0};
    std::uint32_t checksum{0};

    [[nodiscard]] std::string CommandName() const;
    [[nodiscard]] bool IsValid() const;
};

[[nodiscard]] MessageHeader BuildMessageHeader(std::uint32_t magic, const std::string& command,
                                               std::uint32_t payload_size, std::uint32_t checksum);

} // namespace elit21::protocol

#endif // ELIT21_PROTOCOL_H
