#ifndef ELIT21_NODE_CHAINSTATE_H
#define ELIT21_NODE_CHAINSTATE_H

#include "kernel/chainstate.h"

namespace elit21::node {

struct ChainstateStats {
    std::size_t height{0};
    bool has_tip{false};
};

ChainstateStats SnapshotChainstate(const kernel::ChainState& chainstate);

} // namespace elit21::node

#endif // ELIT21_NODE_CHAINSTATE_H
