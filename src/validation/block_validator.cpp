#include "validation/block_validator.h"

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

ValidationResult ValidateBlockLink(
    const std::string& previous_block_hash,
    const std::uint64_t previous_block_timestamp,
    const Block& candidate)
{
    if (candidate.header.previous_block_hash != previous_block_hash) {
        return {false, "candidate.previous_block_hash_mismatch"};
    }

    if (candidate.header.timestamp < previous_block_timestamp) {
        return {false, "candidate.timestamp_before_previous"};
    }

    if (!HasTransactions(candidate)) {
        return {false, "candidate.missing_transactions"};
    }

    return {true, ""};
}

} // namespace elit21::validation
