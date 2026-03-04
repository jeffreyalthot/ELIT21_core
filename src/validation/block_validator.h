#ifndef ELIT21_VALIDATION_BLOCK_VALIDATOR_H
#define ELIT21_VALIDATION_BLOCK_VALIDATOR_H

#include "primitives/block.h"

#include <cstdint>
#include <string>

namespace elit21::validation {

struct ValidationResult {
    bool valid{false};
    std::string reason;
};

ValidationResult ValidateGenesisBlock(const Block& block);
ValidationResult ValidateBlockLink(
    const std::string& previous_block_hash,
    std::uint64_t previous_block_timestamp,
    const Block& candidate);

} // namespace elit21::validation

#endif // ELIT21_VALIDATION_BLOCK_VALIDATOR_H
