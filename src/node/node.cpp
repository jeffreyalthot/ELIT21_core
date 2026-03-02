#include "node/node.h"

#include "validation/block_validator.h"

#include <utility>

namespace elit21::node {

Node::Node(consensus::Params params) : m_params(std::move(params)) {}

bool Node::Start()
{
    m_started = true;
    m_last_validation_error.clear();
    return m_started;
}

bool Node::SubmitBlock(const Block& block)
{
    if (!m_started) {
        m_last_validation_error = "node.not_started";
        return false;
    }

    if (m_chainstate.Tip() == nullptr) {
        const validation::ValidationResult result = validation::ValidateGenesisBlock(block);
        if (!result.valid) {
            m_last_validation_error = result.reason;
            return false;
        }
        m_chainstate.AddBlock(block);
        m_last_validation_error.clear();
        return true;
    }

    const std::size_t next_height = m_chainstate.Height() + 1;
    const validation::ValidationResult result = validation::ValidateBlockLink(*m_chainstate.Tip(), block, next_height);
    if (!result.valid) {
        m_last_validation_error = result.reason;
        return false;
    }

    m_chainstate.AddBlock(block);
    m_last_validation_error.clear();
    return true;
}

const kernel::ChainState& Node::Chain() const
{
    return m_chainstate;
}

const consensus::Params& Node::Params() const
{
    return m_params;
}

const std::string& Node::LastValidationError() const
{
    return m_last_validation_error;
}

} // namespace elit21::node
