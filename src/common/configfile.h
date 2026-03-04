#ifndef ELIT21_COMMON_CONFIGFILE_H
#define ELIT21_COMMON_CONFIGFILE_H

#include <optional>
#include <string>
#include <unordered_map>

namespace elit21::common {

using ConfigMap = std::unordered_map<std::string, std::string>;

std::optional<std::pair<std::string, std::string>> ParseConfigLine(const std::string& line);
ConfigMap ParseConfigText(const std::string& text);

} // namespace elit21::common

#endif // ELIT21_COMMON_CONFIGFILE_H
