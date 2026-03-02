#include "kernel/chainstate.h"

namespace elit21::kernel {

bool ChainState::AddBlock(const Block& block)
{
    if (!m_active_chain.SetTip(block)) {
        return false;
    }

    m_blocks.push_back(block);
    return true;
}

const Block* ChainState::Tip() const
{
    if (m_blocks.empty()) {
        return nullptr;
    }
    return &m_blocks.back();
}

std::size_t ChainState::Height() const
{
    return m_active_chain.Height();
}

bool ChainState::HasBlock(const std::string& block_hash) const
{
    return m_active_chain.Contains(block_hash);
}

} // namespace elit21::kernel
