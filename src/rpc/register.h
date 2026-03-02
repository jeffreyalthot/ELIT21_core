#pragma once

namespace elit21::rpc {

class Server;

void RegisterBlockchainRPC(Server& server);
void RegisterMiningRPC(Server& server);
void RegisterMempoolRPC(Server& server);

} // namespace elit21::rpc
