#ifndef ELIT21_CHAINPARAMSBASE_H
#define ELIT21_CHAINPARAMSBASE_H

#include <cstdint>
#include <string>

namespace elit21 {

struct BaseChainParams {
    std::string network_name;
    std::uint16_t default_p2p_port{0};
    std::uint16_t default_rpc_port{0};
    std::string data_dir;
};

BaseChainParams MainBaseParams();
BaseChainParams TestBaseParams();

} // namespace elit21

#endif // ELIT21_CHAINPARAMSBASE_H
