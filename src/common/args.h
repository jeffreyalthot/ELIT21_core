#ifndef ELIT21_COMMON_ARGS_H
#define ELIT21_COMMON_ARGS_H

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace elit21::common {

class ArgsManager {
public:
    bool ParseParameters(int argc, const char* const argv[]);
    bool ReadConfigFile(const std::string& path);

    [[nodiscard]] bool IsArgSet(const std::string& arg) const;
    [[nodiscard]] std::string GetArg(const std::string& arg, const std::string& default_value) const;
    [[nodiscard]] std::optional<std::string> GetArg(const std::string& arg) const;

private:
    void SetArg(const std::string& key, std::string value);

    std::unordered_map<std::string, std::string> m_args;
};

std::string TrimWhitespace(const std::string& value);

} // namespace elit21::common

#endif // ELIT21_COMMON_ARGS_H
