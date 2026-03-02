#include "util/strencodings.h"

namespace elit21::util {

std::string Join(const std::vector<std::string>& parts, const std::string& separator)
{
    std::string out;
    for (std::size_t i = 0; i < parts.size(); ++i) {
        out += parts[i];
        if (i + 1 < parts.size()) {
            out += separator;
        }
    }
    return out;
}

} // namespace elit21::util
