#include "node/chainman.h"

namespace elit21::node {

bool Chainman::AcceptBlock(const Block& block, std::string& error)
{
    if (m_active_chainstate.Tip() == nullptr) {
        const validation::ValidationResult result = validation::ValidateGenesisBlock(block);
        if (!result.valid) {
            error = result.reason;
            return false;
        }

        m_active_chainstate.AddBlock(block);
        error.clear();
        return true;
    }

    const std::size_t next_height = m_active_chainstate.Height() + 1;
    const validation::ValidationResult result =
        validation::ValidateBlockLink(*m_active_chainstate.Tip(), block, next_height);
    if (!result.valid) {
        error = result.reason;
        return false;
    }

    m_active_chainstate.AddBlock(block);
    error.clear();
    return true;
}

const kernel::ChainState& Chainman::ActiveChain() const
{
    return m_active_chainstate;
}

kernel::ChainState& Chainman::ActiveChain()
{
    return m_active_chainstate;
}

} // namespace elit21::node
