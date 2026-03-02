#ifndef ELIT21_RPC_MINING_H
#define ELIT21_RPC_MINING_H

#include "node/node.h"

#include <string>

namespace elit21::rpc {

std::string GetMiningInfo(const node::Node& node);

} // namespace elit21::rpc

#endif // ELIT21_RPC_MINING_H
