#include "node/node.h"

#include <sstream>

namespace elit21::rpc {

std::string GetBlockchainInfo(const node::Node& node)
{
    std::ostringstream out;
    out << "network=" << node.Params().network_id;
    out << ",height=" << node.Chain().Height();
    out << ",mempool_size=" << node.MempoolSize();
    return out.str();
}

} // namespace elit21::rpc
