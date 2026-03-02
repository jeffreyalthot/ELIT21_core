#ifndef ELIT21_CONSENSUS_MERKLE_H
#define ELIT21_CONSENSUS_MERKLE_H

#include "primitives/block.h"

#include <string>

namespace elit21::consensus {

std::string ComputeMerkleRoot(const std::vector<Transaction>& transactions);

} // namespace elit21::consensus

#endif // ELIT21_CONSENSUS_MERKLE_H
