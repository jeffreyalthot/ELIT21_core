#pragma once

#include <string>

namespace elit21::interfaces {

class Node {
public:
    virtual ~Node() = default;
    virtual std::string Name() const = 0;
};

} // namespace elit21::interfaces
