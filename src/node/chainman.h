#ifndef ELIT21_NODE_CHAINMAN_H
#define ELIT21_NODE_CHAINMAN_H

#include "kernel/chainstate.h"
#include "validation/block_validator.h"

#include <string>

namespace elit21::node {

class Chainman {
public:
    bool AcceptBlock(const Block& block, std::string& error);

    const kernel::ChainState& ActiveChain() const;
    kernel::ChainState& ActiveChain();

private:
    kernel::ChainState m_active_chainstate;
};

} // namespace elit21::node

#endif // ELIT21_NODE_CHAINMAN_H
