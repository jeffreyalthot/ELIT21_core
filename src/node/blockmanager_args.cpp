#include "node/blockmanager_args.h"

namespace elit21::node {

bool IsValidBlockManagerArgs(const BlockManagerArgs& args)
{
    return !args.blocks_dir.empty();
}

} // namespace elit21::node
