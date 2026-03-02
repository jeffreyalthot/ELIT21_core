#include "rpc/register.h"

#include "rpc/server.h"

namespace elit21::rpc {

void RegisterBlockchainRPC(Server& server)
{
    server.RegisterCommand("getblockchaininfo", [](const std::string&) { return std::string{"elit21-blockchain-info"}; });
}

void RegisterMiningRPC(Server& server)
{
    server.RegisterCommand("getmininginfo", [](const std::string&) { return std::string{"elit21-mining-info"}; });
}

void RegisterMempoolRPC(Server& server)
{
    server.RegisterCommand("getmempoolinfo", [](const std::string&) { return std::string{"elit21-mempool-info"}; });
}

} // namespace elit21::rpc
