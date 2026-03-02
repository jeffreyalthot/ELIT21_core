#include "chainparamsbase.h"

namespace elit21 {

BaseChainParams MainBaseParams()
{
    return BaseChainParams{"main", 8333, 8332, "main"};
}

BaseChainParams TestBaseParams()
{
    return BaseChainParams{"test", 18333, 18332, "testnet3"};
}

} // namespace elit21
