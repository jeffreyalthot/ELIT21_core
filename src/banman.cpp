#include "banman.h"

namespace elit21 {

bool BanMan::Ban(const std::string& endpoint)
{
    if (endpoint.empty()) {
        return false;
    }

    return m_banned.insert(endpoint).second;
}

bool BanMan::Unban(const std::string& endpoint)
{
    return m_banned.erase(endpoint) > 0;
}

bool BanMan::IsBanned(const std::string& endpoint) const
{
    return m_banned.count(endpoint) != 0U;
}

std::size_t BanMan::Count() const
{
    return m_banned.size();
}

std::vector<std::string> BanMan::Snapshot() const
{
    return std::vector<std::string>{m_banned.begin(), m_banned.end()};
}

} // namespace elit21
