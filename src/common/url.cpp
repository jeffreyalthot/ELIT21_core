#include "common/url.h"

#include <cctype>
#include <sstream>

namespace elit21::common {

namespace {

int HexValue(const char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    return -1;
}

} // namespace

std::string UrlDecode(const std::string& encoded)
{
    std::string decoded;
    decoded.reserve(encoded.size());

    for (size_t i = 0; i < encoded.size(); ++i) {
        const char ch = encoded[i];
        if (ch == '+' ) {
            decoded.push_back(' ');
            continue;
        }

        if (ch == '%' && (i + 2) < encoded.size()) {
            const int hi = HexValue(encoded[i + 1]);
            const int lo = HexValue(encoded[i + 2]);
            if (hi >= 0 && lo >= 0) {
                decoded.push_back(static_cast<char>((hi << 4) | lo));
                i += 2;
                continue;
            }
        }

        decoded.push_back(ch);
    }

    return decoded;
}

std::map<std::string, std::string> ParseQueryString(const std::string& query)
{
    std::map<std::string, std::string> parsed;
    std::stringstream stream(query);
    std::string item;

    while (std::getline(stream, item, '&')) {
        const auto sep = item.find('=');
        if (sep == std::string::npos) {
            parsed.emplace(UrlDecode(item), std::string{});
            continue;
        }

        const auto key = UrlDecode(item.substr(0, sep));
        const auto value = UrlDecode(item.substr(sep + 1));
        parsed[key] = value;
    }

    return parsed;
}

} // namespace elit21::common
