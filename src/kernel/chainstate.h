#ifndef ELIT21_KERNEL_CHAINSTATE_H
#define ELIT21_KERNEL_CHAINSTATE_H

#include "chain.h"
#include "primitives/block.h"

#include <cstdint>
#include <string>
#include <vector>

namespace elit21::kernel {

class ChainState {
public:
    bool AddBlock(const Block& block);
    bool AddAssumedGenesis(const std::string& block_hash, std::uint64_t timestamp);
    const Block* Tip() const;
    std::size_t Height() const;
    std::string TipHash() const;
    bool HasBlock(const std::string& block_hash) const;

private:
    Chain m_active_chain;
    std::vector<Block> m_blocks;
};

} // namespace elit21::kernel

#endif // ELIT21_KERNEL_CHAINSTATE_H
