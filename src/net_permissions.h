#pragma once

#include <string_view>

namespace elit21 {

enum class NetPermission {
    NoBan,
    Relay,
    ForceRelay,
};

[[nodiscard]] bool IsKnownPermission(std::string_view value);

} // namespace elit21
