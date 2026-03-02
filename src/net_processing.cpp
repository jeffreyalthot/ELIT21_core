#include "net_processing.h"

namespace elit21::net {

bool ProcessNewBlock(node::Node& node, const Block& block, std::string& error)
{
    if (!node.SubmitBlock(block)) {
        error = node.LastValidationError();
        return false;
    }

    error.clear();
    return true;
}

} // namespace elit21::net
