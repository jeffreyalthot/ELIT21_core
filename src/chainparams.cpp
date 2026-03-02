#include "chainparams.h"

namespace elit21 {

ChainParams MainChainParams()
{
    return ChainParams{
        consensus::MainNetParams(),
        MainBaseParams(),
        "f9beb4d9",
        "000000000019d6689c085ae165831e93"
    };
}

ChainParams TestChainParams()
{
    return ChainParams{
        consensus::TestNetParams(),
        TestBaseParams(),
        "0b110907",
        "000000000933ea01ad0ee984209779ba"
    };
}

} // namespace elit21
