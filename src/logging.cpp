#include "logging.h"

#include <algorithm>

namespace elit21 {

std::string_view LogCategoryName(const LogCategory category)
{
    switch (category) {
    case LogCategory::kNet:
        return "net";
    case LogCategory::kRpc:
        return "rpc";
    case LogCategory::kValidation:
        return "validation";
    case LogCategory::kMempool:
        return "mempool";
    case LogCategory::kNode:
        return "node";
    }

    return "unknown";
}

void Logger::Enable(const LogCategory category)
{
    if (!IsEnabled(category)) {
        m_enabled.push_back(category);
    }
}

bool Logger::IsEnabled(const LogCategory category) const
{
    return std::find(m_enabled.begin(), m_enabled.end(), category) != m_enabled.end();
}

void Logger::Log(const LogCategory category, const std::string& message)
{
    if (!IsEnabled(category)) {
        return;
    }

    std::string entry{"["};
    entry += LogCategoryName(category);
    entry += "] ";
    entry += message;
    m_entries.push_back(std::move(entry));
}

std::optional<std::string> Logger::Last() const
{
    if (m_entries.empty()) {
        return std::nullopt;
    }

    return m_entries.back();
}

const std::vector<std::string>& Logger::Entries() const
{
    return m_entries;
}

} // namespace elit21
