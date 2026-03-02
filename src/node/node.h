#ifndef ELIT21_NODE_NODE_H
#define ELIT21_NODE_NODE_H

#include "consensus/params.h"
#include "kernel/chainstate.h"

#include <string>

namespace elit21::node {

class Node {
public:
    explicit Node(consensus::Params params);

    bool Start();
    bool SubmitBlock(const Block& block);

    const kernel::ChainState& Chain() const;
    const consensus::Params& Params() const;

private:
    consensus::Params m_params;
    kernel::ChainState m_chainstate;
    bool m_started{false};
};

} // namespace elit21::node

#endif // ELIT21_NODE_NODE_H
