#pragma once

#include <map>
#include <string>

namespace elit21::common {

[[nodiscard]] std::string UrlDecode(const std::string& encoded);
[[nodiscard]] std::map<std::string, std::string> ParseQueryString(const std::string& query);

} // namespace elit21::common
