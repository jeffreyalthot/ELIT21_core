#ifndef ELIT21_VALIDATION_TX_VALIDATOR_H
#define ELIT21_VALIDATION_TX_VALIDATOR_H

#include "primitives/block.h"

#include <string>

namespace elit21::validation {

struct TxValidationResult {
    bool valid{false};
    std::string reason;
};

TxValidationResult ValidateTransaction(const Transaction& tx);

} // namespace elit21::validation

#endif // ELIT21_VALIDATION_TX_VALIDATOR_H
