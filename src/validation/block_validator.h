#ifndef ELIT21_VALIDATION_BLOCK_VALIDATOR_H
#define ELIT21_VALIDATION_BLOCK_VALIDATOR_H

#include "primitives/block.h"

#include <cstddef>
#include <string>

namespace elit21::validation {

struct ValidationResult {
    bool valid{false};
    std::string reason;
};

ValidationResult ValidateGenesisBlock(const Block& block);
ValidationResult ValidateBlockLink(const Block& previous, const Block& candidate, std::size_t expected_height);

} // namespace elit21::validation

#endif // ELIT21_VALIDATION_BLOCK_VALIDATOR_H
