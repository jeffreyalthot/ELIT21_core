#include "validation/block_validator.h"

#include "crypto/hash.h"

#include <string>

namespace elit21::validation {
namespace {

std::string ComputeBlockId(const BlockHeader& header, std::size_t height)
{
    return crypto::Hash256(
        std::to_string(header.version) + "|" + header.previous_block_hash + "|" + header.merkle_root + "|" +
        std::to_string(header.timestamp) + "|" + std::to_string(header.bits) + "|" + std::to_string(header.nonce) +
        "|" + std::to_string(height));
}

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
    const std::string previous_block_id = ComputeBlockId(previous.header, expected_height - 1);

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
