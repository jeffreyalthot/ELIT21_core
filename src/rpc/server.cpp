#include "rpc/server.h"

namespace elit21::rpc {

bool Server::RegisterCommand(const std::string& name, RpcHandler handler)
{
    return m_handlers.emplace(name, std::move(handler)).second;
}

std::optional<std::string> Server::Call(const std::string& name, const std::string& payload) const
{
    const auto it = m_handlers.find(name);
    if (it == m_handlers.end()) {
        return std::nullopt;
    }
    return it->second(payload);
}

} // namespace elit21::rpc
