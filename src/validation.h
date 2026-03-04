#ifndef ELIT21_VALIDATION_H
#define ELIT21_VALIDATION_H

#include "primitives/block.h"
#include "validation/block_validator.h"
#include "validation/tx_validator.h"

#include <string>

namespace elit21 {

struct ValidationReport {
    bool valid{false};
    std::string reason;
};

ValidationReport ValidateBlockForChain(const Block* previous, const Block& candidate, std::size_t expected_height);
ValidationReport ValidateTransactionStandard(const Transaction& tx);

} // namespace elit21

#endif // ELIT21_VALIDATION_H
