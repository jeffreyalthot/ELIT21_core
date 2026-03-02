#pragma once

#include <string>

namespace elit21::index {

class BaseIndex {
public:
    explicit BaseIndex(std::string name);
    const std::string& Name() const;

private:
    std::string m_name;
};

} // namespace elit21::index
