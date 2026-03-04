#include "kernel/chainstate.h"

#include <utility>

namespace elit21::kernel {

bool ChainState::AddBlock(const Block& block)
{
    if (!m_active_chain.SetTip(block)) {
        return false;
    }

    m_blocks.push_back(block);
    return true;
}

bool ChainState::AddAssumedGenesis(const std::string& block_hash, const std::uint64_t timestamp)
{
    if (!m_active_chain.SetAssumedGenesis(block_hash, timestamp)) {
        return false;
    }

    Block assumed_genesis;
    assumed_genesis.header.previous_block_hash = "0";
    assumed_genesis.header.merkle_root = "assumed-genesis";
    assumed_genesis.header.timestamp = timestamp;
    assumed_genesis.transactions.push_back(Transaction{"assumed-genesis", {}, {"assumed"}});
    m_blocks.push_back(std::move(assumed_genesis));

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

std::string ChainState::TipHash() const
{
    const BlockIndex* tip = m_active_chain.Tip();
    if (tip == nullptr) {
        return "";
    }
    return tip->block_hash;
}

bool ChainState::HasBlock(const std::string& block_hash) const
{
    return m_active_chain.Contains(block_hash);
}

} // namespace elit21::kernel
