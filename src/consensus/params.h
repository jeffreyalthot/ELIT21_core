#ifndef ELIT21_CONSENSUS_PARAMS_H
#define ELIT21_CONSENSUS_PARAMS_H

#include <cstdint>
#include <string>

namespace elit21::consensus {

struct Params {
    std::string network_id{"main"};
    std::uint32_t target_block_time_seconds{600};
    std::uint32_t difficulty_adjustment_interval{2016};
    std::uint64_t initial_block_reward{50};
};

Params MainNetParams();
Params TestNetParams();

} // namespace elit21::consensus

#endif // ELIT21_CONSENSUS_PARAMS_H
