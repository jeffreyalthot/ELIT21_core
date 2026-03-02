#include "amount.h"

namespace elit21 {

bool MoneyRange(const CAmount value)
{
    return value >= 0 && value <= MAX_MONEY;
}

} // namespace elit21
