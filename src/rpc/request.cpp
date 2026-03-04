#include "rpc/request.h"

#include <cctype>

namespace elit21::rpc {

bool IsValidRequest(const Request& request)
{
    if (request.method.empty()) {
        return false;
    }

    for (const unsigned char c : request.method) {
        if (!(std::isalnum(c) || c == '_')) {
            return false;
        }
    }

    return true;
}

} // namespace elit21::rpc
