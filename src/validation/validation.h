#ifndef ELIT21_VALIDATION_VALIDATION_H
#define ELIT21_VALIDATION_VALIDATION_H

#include "primitives/block.h"

#include <string>

namespace elit21::validation {

struct BlockAcceptance {
    bool accepted{false};
    std::string reject_reason;
};

BlockAcceptance ContextualCheckBlock(const Block& block);

} // namespace elit21::validation

#endif // ELIT21_VALIDATION_VALIDATION_H
