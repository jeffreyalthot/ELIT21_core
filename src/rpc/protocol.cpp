#include "rpc/protocol.h"

namespace elit21::rpc {

bool IsRpcVersionSupported(const std::string& version)
{
    return version == kJsonRpcVersionV1 || version == kJsonRpcVersionV2;
}

std::string BuildJsonRpcReply(const std::optional<std::string>& result,
                              const std::optional<std::string>& error,
                              const std::string& id)
{
    const std::string result_field = result.has_value() ? *result : "null";
    const std::string error_field = error.has_value() ? *error : "null";
    return "{\"result\":" + result_field + ",\"error\":" + error_field + ",\"id\":" + id + "}";
}

} // namespace elit21::rpc
