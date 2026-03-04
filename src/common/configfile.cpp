#include "common/configfile.h"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace elit21::common {
namespace {

std::string Trim(std::string value)
{
    const auto not_space = [](unsigned char c) { return !std::isspace(c); };
    value.erase(value.begin(), std::find_if(value.begin(), value.end(), not_space));
    value.erase(std::find_if(value.rbegin(), value.rend(), not_space).base(), value.end());
    return value;
}

} // namespace

std::optional<std::pair<std::string, std::string>> ParseConfigLine(const std::string& line)
{
    const std::string trimmed = Trim(line);
    if (trimmed.empty() || trimmed[0] == '#') {
        return std::nullopt;
    }

    const auto sep = trimmed.find('=');
    if (sep == std::string::npos) {
        return std::nullopt;
    }

    std::string key = Trim(trimmed.substr(0, sep));
    std::string value = Trim(trimmed.substr(sep + 1));

    if (key.empty()) {
        return std::nullopt;
    }

    return std::make_pair(std::move(key), std::move(value));
}

ConfigMap ParseConfigText(const std::string& text)
{
    ConfigMap result;
    std::istringstream input(text);
    std::string line;
    while (std::getline(input, line)) {
        if (const auto kv = ParseConfigLine(line); kv.has_value()) {
            result[kv->first] = kv->second;
        }
    }
    return result;
}

} // namespace elit21::common
