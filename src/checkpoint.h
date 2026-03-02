#pragma once

#include <cstdint>
#include <map>
#include <string>

namespace elit21 {

using CheckpointMap = std::map<std::int32_t, std::string>;

bool IsCheckpointed(const CheckpointMap& checkpoints, std::int32_t height, const std::string& block_hash);

} // namespace elit21
