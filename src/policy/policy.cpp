#include "policy/policy.h"

namespace elit21::policy {

bool IsStandardTx(const Transaction& tx)
{
    return !tx.outputs.empty() && tx.outputs.size() <= MAX_STANDARD_TX_OUTPUTS;
}

} // namespace elit21::policy
