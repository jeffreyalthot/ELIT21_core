#include "chainparams.h"

#include <cassert>

int main()
{
    const elit21::ChainParams main_params = elit21::MainChainParams();
    const elit21::ChainParams test_params = elit21::TestChainParams();

    assert(main_params.consensus.network_id == "main");
    assert(main_params.base.default_p2p_port == 8333);
    assert(!main_params.genesis_block_hash.empty());

    assert(test_params.consensus.network_id == "test");
    assert(test_params.base.default_p2p_port == 18333);
    assert(!test_params.message_start.empty());

    return 0;
}
