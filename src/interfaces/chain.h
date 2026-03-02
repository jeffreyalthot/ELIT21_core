#ifndef ELIT21_INTERFACES_CHAIN_H
#define ELIT21_INTERFACES_CHAIN_H

#include "primitives/block.h"

namespace elit21::interfaces {

class IChain {
public:
    virtual ~IChain() = default;
    virtual bool SubmitBlock(const Block& block) = 0;
    virtual std::size_t Height() const = 0;
};

} // namespace elit21::interfaces

#endif // ELIT21_INTERFACES_CHAIN_H
