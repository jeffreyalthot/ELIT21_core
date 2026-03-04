#include "node/blockmanager_opts.h"

namespace elit21::node {

bool ValidateBlockManagerOpts(const BlockManagerOpts& opts)
{
    if (opts.max_blockfile_size_mb < 8) {
        return false;
    }
    if (opts.fast_prune && opts.prune_target_mb == 0) {
        return false;
    }
    return true;
}

std::string BuildBlockManagerSummary(const BlockManagerOpts& opts)
{
    return "maxblk=" + std::to_string(opts.max_blockfile_size_mb) + "MB, prune=" +
           std::to_string(opts.prune_target_mb) + "MB, fastprune=" + (opts.fast_prune ? "1" : "0");
}

} // namespace elit21::node
