#include "checkpoint.h"

namespace elit21 {

bool IsCheckpointed(const CheckpointMap& checkpoints, const std::int32_t height, const std::string& block_hash)
{
    const auto it = checkpoints.find(height);
    if (it == checkpoints.end()) {
        return true;
    }
    return it->second == block_hash;
}

} // namespace elit21
