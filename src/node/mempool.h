#ifndef ELIT21_NODE_MEMPOOL_H
#define ELIT21_NODE_MEMPOOL_H

#include "primitives/block.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace elit21::node {

class Mempool {
public:
    bool Add(const Transaction& tx, std::string& error);
    std::size_t Size() const;
    std::vector<Transaction> Snapshot() const;

private:
    std::vector<Transaction> m_txs;
    std::unordered_set<std::string> m_known_txids;
};

} // namespace elit21::node

#endif // ELIT21_NODE_MEMPOOL_H
