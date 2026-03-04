#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace elit21 {

enum class LogCategory {
    kNet,
    kRpc,
    kValidation,
    kMempool,
    kNode,
};

[[nodiscard]] std::string_view LogCategoryName(LogCategory category);

class Logger {
public:
    void Enable(LogCategory category);
    bool IsEnabled(LogCategory category) const;

    void Log(LogCategory category, const std::string& message);
    [[nodiscard]] std::optional<std::string> Last() const;
    [[nodiscard]] const std::vector<std::string>& Entries() const;

private:
    std::vector<LogCategory> m_enabled;
    std::vector<std::string> m_entries;
};

} // namespace elit21
