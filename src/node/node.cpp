#include "node/node.h"

namespace elit21::node {

Node::Node(consensus::Params params) : m_params(std::move(params)) {}

bool Node::Start()
{
    m_started = true;
    return m_started;
}

bool Node::SubmitBlock(const Block& block)
{
    if (!m_started) {
        return false;
    }

    m_chainstate.AddBlock(block);
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

} // namespace elit21::node
