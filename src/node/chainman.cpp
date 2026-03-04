#include "node/chainman.h"

namespace elit21::node {

bool Chainman::AcceptBlock(const Block& block, std::string& error)
{
    if (m_active_chainstate.Tip() == nullptr) {
        const validation::ValidationResult genesis_result = validation::ValidateGenesisBlock(block);
        if (genesis_result.valid) {
            if (!m_active_chainstate.AddBlock(block)) {
                error = "chainstate.add_block_failed";
                return false;
            }
            error.clear();
            return true;
        }

        if (block.header.previous_block_hash.empty()) {
            error = genesis_result.reason;
            return false;
        }

        if (!m_active_chainstate.AddAssumedGenesis(block.header.previous_block_hash, block.header.timestamp)) {
            error = "chainstate.add_assumed_genesis_failed";
            return false;
        }
    }

    const validation::ValidationResult result =
        validation::ValidateBlockLink(m_active_chainstate.TipHash(), m_active_chainstate.Tip()->header.timestamp, block);
    if (!result.valid) {
        error = result.reason;
        return false;
    }

    if (!m_active_chainstate.AddBlock(block)) {
        error = "chainstate.add_block_failed";
        return false;
    }

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
