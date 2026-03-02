#include "rpc/mempool.h"

#include <sstream>

namespace elit21::rpc {

std::string GetMempoolInfo(const node::Node& node)
{
    std::ostringstream out;
    out << "size=" << node.MempoolSize();
    return out.str();
}

} // namespace elit21::rpc
