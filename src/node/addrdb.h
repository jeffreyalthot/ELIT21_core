#pragma once

#include <string>

namespace elit21::node {

class AddrDB {
public:
    explicit AddrDB(std::string path);

    [[nodiscard]] const std::string& Path() const;

private:
    std::string m_path;
};

} // namespace elit21::node
