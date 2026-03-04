#ifndef ELIT21_RPC_REQUEST_H
#define ELIT21_RPC_REQUEST_H

#include <string>
#include <vector>

namespace elit21::rpc {

struct Request {
    std::string method;
    std::vector<std::string> params;
};

bool IsValidRequest(const Request& request);

} // namespace elit21::rpc

#endif // ELIT21_RPC_REQUEST_H
