#pragma once

#include <cstdint>

namespace elit21 {

struct VersionBitsState {
    std::uint32_t bit{0};
    bool active{false};
};

bool IsVersionBitSet(std::uint32_t version, std::uint32_t bit);

} // namespace elit21
