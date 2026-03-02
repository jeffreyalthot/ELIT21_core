#pragma once

#include <functional>
#include <optional>
#include <string>
#include <unordered_map>

namespace elit21::rpc {

using RpcHandler = std::function<std::string(const std::string&)>;

class Server {
public:
    bool RegisterCommand(const std::string& name, RpcHandler handler);
    std::optional<std::string> Call(const std::string& name, const std::string& payload) const;

private:
    std::unordered_map<std::string, RpcHandler> m_handlers;
};

} // namespace elit21::rpc
