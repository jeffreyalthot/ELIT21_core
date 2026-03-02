#ifndef ELIT21_TXDB_H
#define ELIT21_TXDB_H

#include <optional>
#include <string>
#include <unordered_map>

namespace elit21 {

class TxDB {
public:
    bool WriteBestBlockHash(const std::string& block_hash);
    std::optional<std::string> ReadBestBlockHash() const;
    bool WriteTxHeight(const std::string& txid, int height);
    std::optional<int> ReadTxHeight(const std::string& txid) const;

private:
    std::optional<std::string> m_best_block_hash;
    std::unordered_map<std::string, int> m_tx_heights;
};

} // namespace elit21

#endif // ELIT21_TXDB_H
