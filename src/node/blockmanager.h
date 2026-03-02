#ifndef ELIT21_NODE_BLOCKMANAGER_H
#define ELIT21_NODE_BLOCKMANAGER_H

#include "primitives/block.h"

#include <cstddef>
#include <string>
#include <unordered_set>

namespace elit21::node {

class BlockManager {
public:
    bool AcceptBlock(const Block& block, std::string& error);
    std::size_t StoredBlockCount() const;

private:
    std::unordered_set<std::string> m_known_block_ids;
};

} // namespace elit21::node

#endif // ELIT21_NODE_BLOCKMANAGER_H
