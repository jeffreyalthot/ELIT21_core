#include "validation.h"

#include "chain.h"

namespace elit21 {

ValidationReport ValidateBlockForChain(const Block* previous, const Block& candidate, const std::size_t expected_height)
{
    if (previous == nullptr) {
        const auto result = validation::ValidateGenesisBlock(candidate);
        return {result.valid, result.reason};
    }

    const std::string previous_block_hash = ComputeBlockHash(previous->header, expected_height - 1);
    const auto result = validation::ValidateBlockLink(previous_block_hash, previous->header.timestamp, candidate);
    return {result.valid, result.reason};
}

ValidationReport ValidateTransactionStandard(const Transaction& tx)
{
    const auto result = validation::ValidateTransaction(tx);
    return {result.valid, result.reason};
}

} // namespace elit21
