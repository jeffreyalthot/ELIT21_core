#include "pow.h"

#include "crypto/hash.h"

#include <string>

namespace elit21::pow {

bool CheckProofOfWork(const BlockHeader& header)
{
    const std::string hash = crypto::Hash256(
        std::to_string(header.version) + header.previous_block_hash + header.merkle_root +
        std::to_string(header.timestamp) + std::to_string(header.bits) + std::to_string(header.nonce));

    if (header.bits == 0) {
        return false;
    }

    const std::size_t required_prefix = static_cast<std::size_t>(header.bits % 4);
    for (std::size_t i = 0; i < required_prefix && i < hash.size(); ++i) {
        if (hash[i] != '0') {
            return false;
        }
    }

    return true;
}

} // namespace elit21::pow
