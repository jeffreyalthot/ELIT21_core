#include "node/blockmanager.h"

#include "chain.h"

namespace elit21::node {

bool BlockManager::AcceptBlock(const Block& block, std::string& error)
{
    if (block.transactions.empty()) {
        error = "blockmanager.empty_block";
        return false;
    }

    const std::string block_id = ComputeBlockHash(block.header, block.transactions.size());
    const auto [it, inserted] = m_known_block_ids.insert(block_id);
    (void)it;
    if (!inserted) {
        error = "blockmanager.duplicate_block";
        return false;
    }

    error.clear();
    return true;
}

std::size_t BlockManager::StoredBlockCount() const
{
    return m_known_block_ids.size();
}

} // namespace elit21::node
