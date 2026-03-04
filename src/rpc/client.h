#ifndef ELIT21_RPC_CLIENT_H
#define ELIT21_RPC_CLIENT_H

#include <string>
#include <vector>

namespace elit21::rpc {

struct RPCCommand {
    std::string method;
    std::vector<std::string> params;
};

RPCCommand ParseCommandLineRequest(const std::vector<std::string>& argv);

} // namespace elit21::rpc

#endif // ELIT21_RPC_CLIENT_H
