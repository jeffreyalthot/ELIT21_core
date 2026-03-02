#include "validation/block_validator.h"

#include "chain.h"

#include <string>

namespace elit21::validation {
namespace {

bool HasTransactions(const Block& block)
{
    return !block.transactions.empty();
}

} // namespace

ValidationResult ValidateGenesisBlock(const Block& block)
{
    if (block.header.previous_block_hash != "0") {
        return {false, "genesis.previous_block_hash_must_be_0"};
    }

    if (!HasTransactions(block)) {
        return {false, "genesis.missing_transactions"};
    }

    if (block.header.merkle_root.empty()) {
        return {false, "genesis.merkle_root_empty"};
    }

    return {true, ""};
}

ValidationResult ValidateBlockLink(const Block& previous, const Block& candidate, const std::size_t expected_height)
{
    const std::string previous_block_id = ComputeBlockHash(previous.header, expected_height - 1);

    if (candidate.header.previous_block_hash != previous_block_id) {
        return {false, "candidate.previous_block_hash_mismatch"};
    }

    if (candidate.header.timestamp < previous.header.timestamp) {
        return {false, "candidate.timestamp_before_previous"};
    }

    if (!HasTransactions(candidate)) {
        return {false, "candidate.missing_transactions"};
    }

    return {true, ""};
}

} // namespace elit21::validation
