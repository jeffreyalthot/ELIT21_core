#pragma once

#include <optional>
#include <string>

namespace elit21::rpc {

inline constexpr const char* kJsonRpcVersionV1 = "1.0";
inline constexpr const char* kJsonRpcVersionV2 = "2.0";

[[nodiscard]] bool IsRpcVersionSupported(const std::string& version);
[[nodiscard]] std::string BuildJsonRpcReply(const std::optional<std::string>& result,
                                            const std::optional<std::string>& error,
                                            const std::string& id);

} // namespace elit21::rpc
