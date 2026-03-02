#pragma once

#include <cstdint>

namespace elit21 {

using CAmount = std::int64_t;

constexpr CAmount COIN = 100000000;
constexpr CAmount MAX_MONEY = 21000000LL * COIN;

bool MoneyRange(CAmount value);

} // namespace elit21
