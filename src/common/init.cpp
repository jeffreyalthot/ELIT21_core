#include "common/init.h"

namespace elit21::common {

bool IsSupportedNetwork(const std::string& network)
{
    return network == "main" || network == "test" || network == "regtest";
}

bool IsDataDirConfigured(const InitConfig& config)
{
    return !config.data_dir.empty();
}

} // namespace elit21::common
