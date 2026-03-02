#include "rpc/mining.h"

#include <sstream>

namespace elit21::rpc {

std::string GetMiningInfo(const node::Node& node)
{
    std::ostringstream out;
    out << "network=" << node.Params().network_id;
    out << ",target_block_time=" << node.Params().target_block_time_seconds;
    out << ",difficulty_interval=" << node.Params().difficulty_adjustment_interval;
    return out.str();
}

} // namespace elit21::rpc
