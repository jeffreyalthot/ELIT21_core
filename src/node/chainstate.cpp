#include "node/chainstate.h"

namespace elit21::node {

ChainstateStats SnapshotChainstate(const kernel::ChainState& chainstate)
{
    return ChainstateStats{chainstate.Height(), chainstate.Tip() != nullptr};
}

} // namespace elit21::node
