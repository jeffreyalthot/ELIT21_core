#include "rpc/util.h"

#include <algorithm>
#include <cctype>

namespace elit21::rpc {

std::string NormalizeRpcMethod(std::string method)
{
    std::transform(method.begin(), method.end(), method.begin(), [](const unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return method;
}

} // namespace elit21::rpc
