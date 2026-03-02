#ifndef ELIT21_POLICY_POLICY_H
#define ELIT21_POLICY_POLICY_H

#include "primitives/block.h"

#include <cstddef>

namespace elit21::policy {

constexpr std::size_t MAX_STANDARD_TX_OUTPUTS = 4;

bool IsStandardTx(const Transaction& tx);

} // namespace elit21::policy

#endif // ELIT21_POLICY_POLICY_H
