#include "node/node.h"

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

    std::string block_error;
    if (!m_block_manager.AcceptBlock(block, block_error)) {
        m_last_validation_error = block_error;
        return false;
    }

    if (!m_chainman.AcceptBlock(block, m_last_validation_error)) {
        return false;
    }

    m_validation_signals.NotifyBlockTip(block, m_chainman.ActiveChain().Height());
    m_last_validation_error.clear();
    return true;
}

bool Node::SubmitTransaction(const Transaction& tx)
{
    if (!m_started) {
        m_last_validation_error = "node.not_started";
        return false;
    }

    std::string error;
    if (!m_mempool.Add(tx, error)) {
        m_last_validation_error = error;
        return false;
    }

    m_validation_signals.NotifyTransactionAdded(tx);
    m_last_validation_error.clear();
    return true;
}

const kernel::ChainState& Node::Chain() const
{
    return m_chainman.ActiveChain();
}

const consensus::Params& Node::Params() const
{
    return m_params;
}

const std::string& Node::LastValidationError() const
{
    return m_last_validation_error;
}

std::size_t Node::MempoolSize() const
{
    return m_mempool.Size();
}

std::size_t Node::KnownBlocks() const
{
    return m_block_manager.StoredBlockCount();
}

NodeContext Node::BuildContext()
{
    return NodeContext{&m_chainman.ActiveChain(), &m_mempool, &m_block_manager, &m_peer_manager, &m_validation_signals};
}

} // namespace elit21::node
