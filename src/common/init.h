#pragma once

#include <string>

namespace elit21::common {

struct InitConfig {
    std::string network{"main"};
    std::string data_dir{"./data"};
};

[[nodiscard]] bool IsSupportedNetwork(const std::string& network);
[[nodiscard]] bool IsDataDirConfigured(const InitConfig& config);

} // namespace elit21::common
