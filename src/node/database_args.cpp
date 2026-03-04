#include "node/database_args.h"

namespace elit21::node {

std::string BuildBlocksPath(const std::string& data_dir, const DatabaseArgs& args)
{
    return data_dir + "/" + args.blocks_dir;
}

std::string BuildChainstatePath(const std::string& data_dir, const DatabaseArgs& args)
{
    return data_dir + "/" + args.chainstate_dir;
}

} // namespace elit21::node
