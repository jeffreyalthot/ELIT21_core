#pragma once

#include <cstdint>
#include <string>

namespace elit21::util {

[[nodiscard]] std::int64_t GetTimeSeconds();
[[nodiscard]] std::string FormatISO8601(std::int64_t timestamp);

} // namespace elit21::util
