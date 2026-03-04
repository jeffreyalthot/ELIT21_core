#ifndef ELIT21_NODE_BLOCKMANAGER_OPTS_H
#define ELIT21_NODE_BLOCKMANAGER_OPTS_H

#include <cstddef>
#include <string>

namespace elit21::node {

struct BlockManagerOpts {
    std::size_t max_blockfile_size_mb{128};
    std::size_t prune_target_mb{0};
    bool fast_prune{false};
};

bool ValidateBlockManagerOpts(const BlockManagerOpts& opts);
std::string BuildBlockManagerSummary(const BlockManagerOpts& opts);

} // namespace elit21::node

#endif // ELIT21_NODE_BLOCKMANAGER_OPTS_H
