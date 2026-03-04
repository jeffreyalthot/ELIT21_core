#ifndef ELIT21_COMMON_SETTINGS_H
#define ELIT21_COMMON_SETTINGS_H

#include <optional>
#include <string>
#include <unordered_map>

namespace elit21::common {

class Settings {
public:
    void Set(std::string key, std::string value);
    std::optional<std::string> Get(const std::string& key) const;
    bool Has(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> m_values;
};

} // namespace elit21::common

#endif // ELIT21_COMMON_SETTINGS_H
