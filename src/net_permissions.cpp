#include "net_permissions.h"

namespace elit21 {

bool IsKnownPermission(const std::string_view value)
{
    return value == "noban" || value == "relay" || value == "forcerelay";
}

} // namespace elit21
