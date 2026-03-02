#ifndef ELIT21_CHAIN_H
#define ELIT21_CHAIN_H

#include "primitives/block.h"

#include <cstddef>
#include <string>
#include <vector>

namespace elit21 {

struct BlockIndex {
    std::size_t height{0};
    std::string block_hash;
    BlockHeader header;
};

std::string ComputeBlockHash(const BlockHeader& header, std::size_t height);

class Chain {
public:
    bool SetTip(const Block& block);
    const BlockIndex* Tip() const;
    const BlockIndex* AtHeight(std::size_t height) const;
    std::size_t Height() const;
    bool Contains(const std::string& block_hash) const;

private:
    std::vector<BlockIndex> m_chain;
};

} // namespace elit21

#endif // ELIT21_CHAIN_H
