#include "node/types.h"

namespace elit21::node {

std::string BuildUserAgent(const std::string& node_name, const std::string& version)
{
    return "/" + node_name + ":" + version + "/";
}

} // namespace elit21::node
