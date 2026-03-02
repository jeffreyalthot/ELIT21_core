#include "txdb.h"

namespace elit21 {

bool TxDB::WriteBestBlockHash(const std::string& block_hash)
{
    if (block_hash.empty()) {
        return false;
    }

    m_best_block_hash = block_hash;
    return true;
}

std::optional<std::string> TxDB::ReadBestBlockHash() const
{
    return m_best_block_hash;
}

bool TxDB::WriteTxHeight(const std::string& txid, const int height)
{
    if (txid.empty() || height < 0) {
        return false;
    }

    m_tx_heights[txid] = height;
    return true;
}

std::optional<int> TxDB::ReadTxHeight(const std::string& txid) const
{
    const auto it = m_tx_heights.find(txid);
    if (it == m_tx_heights.end()) {
        return std::nullopt;
    }

    return it->second;
}

} // namespace elit21
