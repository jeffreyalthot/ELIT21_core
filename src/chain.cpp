#include "chain.h"

#include "crypto/hash.h"

#include <algorithm>

namespace elit21 {

std::string ComputeBlockHash(const BlockHeader& header, const std::size_t height)
{
    return crypto::Hash256(
        std::to_string(header.version) + "|" + header.previous_block_hash + "|" + header.merkle_root + "|" +
        std::to_string(header.timestamp) + "|" + std::to_string(header.bits) + "|" + std::to_string(header.nonce) +
        "|" + std::to_string(height));
}

bool Chain::SetTip(const Block& block)
{
    const std::size_t next_height = m_chain.size();

    if (!m_chain.empty()) {
        const std::string expected_prev = m_chain.back().block_hash;
        if (block.header.previous_block_hash != expected_prev) {
            return false;
        }
    }

    BlockIndex index;
    index.height = next_height;
    index.header = block.header;
    index.block_hash = ComputeBlockHash(block.header, next_height);
    m_chain.push_back(index);

    return true;
}

const BlockIndex* Chain::Tip() const
{
    if (m_chain.empty()) {
        return nullptr;
    }
    return &m_chain.back();
}

const BlockIndex* Chain::AtHeight(const std::size_t height) const
{
    if (height >= m_chain.size()) {
        return nullptr;
    }
    return &m_chain[height];
}

std::size_t Chain::Height() const
{
    return m_chain.empty() ? 0 : m_chain.size() - 1;
}

bool Chain::Contains(const std::string& block_hash) const
{
    return std::any_of(m_chain.begin(), m_chain.end(), [&](const BlockIndex& index) {
        return index.block_hash == block_hash;
    });
}

} // namespace elit21
