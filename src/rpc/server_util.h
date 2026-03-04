#pragma once

#include <optional>
#include <string>

namespace elit21::rpc {

[[nodiscard]] std::optional<int> ParseRpcTimeoutSeconds(const std::string& value);
[[nodiscard]] std::string FormatRpcError(int code, const std::string& message);

} // namespace elit21::rpc
