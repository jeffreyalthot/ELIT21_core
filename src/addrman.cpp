#include "addrman.h"

namespace elit21 {

bool AddrMan::Add(const std::string& endpoint)
{
    if (endpoint.empty() || m_entries.count(endpoint) != 0U) {
        return false;
    }

    m_entries.emplace(endpoint, Entry{});
    return true;
}

bool AddrMan::MarkGood(const std::string& endpoint)
{
    const auto it = m_entries.find(endpoint);
    if (it == m_entries.end()) {
        return false;
    }

    it->second.is_good = true;
    return true;
}

bool AddrMan::IsKnown(const std::string& endpoint) const
{
    return m_entries.count(endpoint) != 0U;
}

std::size_t AddrMan::Size() const
{
    return m_entries.size();
}

std::vector<std::string> AddrMan::GetAll() const
{
    std::vector<std::string> endpoints;
    endpoints.reserve(m_entries.size());

    for (const auto& [endpoint, _] : m_entries) {
        endpoints.push_back(endpoint);
    }

    return endpoints;
}

} // namespace elit21
