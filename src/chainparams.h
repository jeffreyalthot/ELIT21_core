#ifndef ELIT21_CHAINPARAMS_H
#define ELIT21_CHAINPARAMS_H

#include "chainparamsbase.h"
#include "consensus/params.h"

namespace elit21 {

struct ChainParams {
    consensus::Params consensus;
    BaseChainParams base;
    std::string message_start;
    std::string genesis_block_hash;
};

ChainParams MainChainParams();
ChainParams TestChainParams();

} // namespace elit21

#endif // ELIT21_CHAINPARAMS_H
