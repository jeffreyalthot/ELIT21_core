#include "node/node.h"

#include <sstream>

namespace elit21::rpc {

std::string GetBlockchainInfo(const node::Node& node)
{
    std::ostringstream out;
    out << "network=" << node.Params().network_id;
    out << ",height=" << node.Chain().Height();
    return out.str();
}

} // namespace elit21::rpc
