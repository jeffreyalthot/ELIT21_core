#ifndef ELIT21_KERNEL_CHAINSTATE_H
#define ELIT21_KERNEL_CHAINSTATE_H

#include "primitives/block.h"

#include <vector>

namespace elit21::kernel {

class ChainState {
public:
    void AddBlock(const Block& block);
    const Block* Tip() const;
    std::size_t Height() const;

private:
    std::vector<Block> m_chain;
};

} // namespace elit21::kernel

#endif // ELIT21_KERNEL_CHAINSTATE_H
