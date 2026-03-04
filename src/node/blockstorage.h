#pragma once

#include <cstdint>

namespace elit21::node {

struct BlockStorageInfo {
    std::uint64_t files_count{0};
    std::uint64_t total_bytes{0};
};

[[nodiscard]] BlockStorageInfo GetDefaultBlockStorageInfo();

} // namespace elit21::node
