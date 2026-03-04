#include "common/settings.h"

namespace elit21::common {

void Settings::Set(std::string key, std::string value)
{
    m_values[std::move(key)] = std::move(value);
}

std::optional<std::string> Settings::Get(const std::string& key) const
{
    const auto it = m_values.find(key);
    if (it == m_values.end()) {
        return std::nullopt;
    }

    return it->second;
}

bool Settings::Has(const std::string& key) const
{
    return m_values.find(key) != m_values.end();
}

} // namespace elit21::common
