#pragma once

#include <string>

namespace elit21::node {

struct DatabaseArgs {
    std::string blocks_dir{"blocks"};
    std::string chainstate_dir{"chainstate"};
};

[[nodiscard]] std::string BuildBlocksPath(const std::string& data_dir, const DatabaseArgs& args);
[[nodiscard]] std::string BuildChainstatePath(const std::string& data_dir, const DatabaseArgs& args);

} // namespace elit21::node
