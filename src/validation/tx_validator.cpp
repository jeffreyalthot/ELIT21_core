#include "validation/tx_validator.h"

namespace elit21::validation {

TxValidationResult ValidateTransaction(const Transaction& tx)
{
    if (tx.txid.empty()) {
        return {false, "tx.txid_empty"};
    }

    if (tx.inputs.empty() && tx.outputs.empty()) {
        return {false, "tx.empty_io"};
    }

    if (tx.outputs.empty()) {
        return {false, "tx.outputs_empty"};
    }

    return {true, ""};
}

} // namespace elit21::validation
