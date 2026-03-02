#include "consensus/merkle.h"

#include "crypto/hash.h"

#include <vector>

namespace elit21::consensus {

std::string ComputeMerkleRoot(const std::vector<Transaction>& transactions)
{
    if (transactions.empty()) {
        return {};
    }

    std::vector<std::string> level;
    level.reserve(transactions.size());
    for (const Transaction& tx : transactions) {
        level.push_back(tx.txid);
    }

    while (level.size() > 1) {
        if (level.size() % 2 != 0) {
            level.push_back(level.back());
        }

        std::vector<std::string> next;
        next.reserve(level.size() / 2);
        for (std::size_t i = 0; i < level.size(); i += 2) {
            next.push_back(crypto::Hash256(level[i] + level[i + 1]));
        }
        level = std::move(next);
    }

    return level.front();
}

} // namespace elit21::consensus
