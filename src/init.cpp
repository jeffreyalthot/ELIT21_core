#include "init.h"

namespace elit21 {

bool AppInitMain(node::NodeContext& node_context)
{
    return node_context.chainstate != nullptr &&
           node_context.mempool != nullptr &&
           node_context.block_manager != nullptr &&
           node_context.peer_manager != nullptr &&
           node_context.validation_signals != nullptr;
}

} // namespace elit21
