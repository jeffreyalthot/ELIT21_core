#include "validation/validation.h"

#include "consensus/merkle.h"
#include "pow.h"

namespace elit21::validation {

BlockAcceptance ContextualCheckBlock(const Block& block)
{
    if (block.transactions.empty()) {
        return {false, "bad-blk-empty"};
    }

    if (consensus::ComputeMerkleRoot(block.transactions) != block.header.merkle_root) {
        return {false, "bad-txnmrklroot"};
    }

    if (!pow::CheckProofOfWork(block.header)) {
        return {false, "high-hash"};
    }

    return {true, ""};
}

} // namespace elit21::validation
