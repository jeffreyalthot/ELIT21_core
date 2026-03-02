#include "common/args.h"

#include <cctype>
#include <fstream>
#include <sstream>

namespace elit21::common {

namespace {

constexpr const char* kDash = "-";

bool IsCommentOrEmpty(const std::string& line)
{
    const std::string trimmed = TrimWhitespace(line);
    return trimmed.empty() || trimmed[0] == '#';
}

std::optional<std::pair<std::string, std::string>> ParseConfigLine(const std::string& line)
{
    const std::size_t separator = line.find('=');
    if (separator == std::string::npos) {
        return std::nullopt;
    }

    std::string key = TrimWhitespace(line.substr(0, separator));
    std::string value = TrimWhitespace(line.substr(separator + 1));
    if (key.empty()) {
        return std::nullopt;
    }

    return std::make_pair(key, value);
}

} // namespace

std::string TrimWhitespace(const std::string& value)
{
    std::size_t begin = 0;
    while (begin < value.size() && std::isspace(static_cast<unsigned char>(value[begin])) != 0) {
        ++begin;
    }

    std::size_t end = value.size();
    while (end > begin && std::isspace(static_cast<unsigned char>(value[end - 1])) != 0) {
        --end;
    }

    return value.substr(begin, end - begin);
}

bool ArgsManager::ParseParameters(const int argc, const char* const argv[])
{
    for (int i = 1; i < argc; ++i) {
        const std::string token(argv[i]);
        if (token.rfind(kDash, 0) != 0) {
            continue;
        }

        const std::size_t separator = token.find('=');
        if (separator == std::string::npos) {
            SetArg(token.substr(1), "1");
            continue;
        }

        const std::string key = token.substr(1, separator - 1);
        const std::string value = token.substr(separator + 1);
        SetArg(key, value);
    }

    return true;
}

bool ArgsManager::ReadConfigFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (IsCommentOrEmpty(line)) {
            continue;
        }

        const auto parsed = ParseConfigLine(line);
        if (!parsed.has_value()) {
            continue;
        }

        const auto& [key, value] = *parsed;
        if (!IsArgSet(key)) {
            SetArg(key, value);
        }
    }

    return true;
}

bool ArgsManager::IsArgSet(const std::string& arg) const
{
    return m_args.find(arg) != m_args.end();
}

std::string ArgsManager::GetArg(const std::string& arg, const std::string& default_value) const
{
    const auto it = m_args.find(arg);
    if (it == m_args.end()) {
        return default_value;
    }
    return it->second;
}

std::optional<std::string> ArgsManager::GetArg(const std::string& arg) const
{
    const auto it = m_args.find(arg);
    if (it == m_args.end()) {
        return std::nullopt;
    }
    return it->second;
}

void ArgsManager::SetArg(const std::string& key, std::string value)
{
    m_args[key] = std::move(value);
}

} // namespace elit21::common
