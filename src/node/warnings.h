#pragma once

#include <optional>
#include <string>

namespace elit21::node {

class Warnings {
public:
    void Set(const std::string& warning);
    std::optional<std::string> Get() const;

private:
    std::optional<std::string> m_warning;
};

} // namespace elit21::node
