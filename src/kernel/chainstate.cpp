#include "kernel/chainstate.h"

namespace elit21::kernel {

void ChainState::AddBlock(const Block& block)
{
    m_chain.push_back(block);
}

const Block* ChainState::Tip() const
{
    if (m_chain.empty()) {
        return nullptr;
    }
    return &m_chain.back();
}

std::size_t ChainState::Height() const
{
    return m_chain.empty() ? 0 : m_chain.size() - 1;
}

} // namespace elit21::kernel
