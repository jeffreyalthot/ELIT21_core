#pragma once

#include <cstddef>
#include <string>

namespace elit21::node {

struct MempoolArgs {
    size_t max_mempool_mb{300};
    int expiry_hours{336};
    bool persist{true};
};

[[nodiscard]] bool ValidateMempoolArgs(const MempoolArgs& args);
[[nodiscard]] std::string BuildMempoolArgsSummary(const MempoolArgs& args);

} // namespace elit21::node
