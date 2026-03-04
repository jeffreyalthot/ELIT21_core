#include "rpc/server_util.h"

#include <charconv>
#include <system_error>

namespace elit21::rpc {

std::optional<int> ParseRpcTimeoutSeconds(const std::string& value)
{
    int parsed{0};
    const auto* first = value.data();
    const auto* last = value.data() + value.size();
    const auto [ptr, ec] = std::from_chars(first, last, parsed);
    if (ec != std::errc{} || ptr != last || parsed < 0) {
        return std::nullopt;
    }
    return parsed;
}

std::string FormatRpcError(const int code, const std::string& message)
{
    return "{" + std::string{"\"code\":"} + std::to_string(code) + ",\"message\":\"" + message + "\"}";
}

} // namespace elit21::rpc
