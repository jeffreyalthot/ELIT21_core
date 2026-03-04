#include "rpc/blockchain_util.h"

#include <charconv>

namespace elit21::rpc {

std::optional<int> ParseBlockHeight(const std::string& value)
{
    if (value.empty()) {
        return std::nullopt;
    }

    int parsed = 0;
    const auto* begin = value.data();
    const auto* end = value.data() + value.size();
    const auto result = std::from_chars(begin, end, parsed);
    if (result.ec != std::errc{} || result.ptr != end || parsed < 0) {
        return std::nullopt;
    }

    return parsed;
}

std::string BuildBlockRangeDescriptor(const int start_height, const int end_height)
{
    if (start_height < 0 || end_height < start_height) {
        return "invalid";
    }
    return "range:" + std::to_string(start_height) + "-" + std::to_string(end_height);
}

} // namespace elit21::rpc
