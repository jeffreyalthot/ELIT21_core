#ifndef ELIT21_NODE_BLOCKMANAGER_ARGS_H
#define ELIT21_NODE_BLOCKMANAGER_ARGS_H

#include <string>

namespace elit21::node {

struct BlockManagerArgs {
    std::string blocks_dir{"blocks"};
    bool prune{false};
};

bool IsValidBlockManagerArgs(const BlockManagerArgs& args);

} // namespace elit21::node

#endif // ELIT21_NODE_BLOCKMANAGER_ARGS_H
