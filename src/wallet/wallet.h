#pragma once

#include <string>

namespace elit21::wallet {

class Wallet {
public:
    explicit Wallet(std::string label);
    const std::string& Label() const;

private:
    std::string m_label;
};

} // namespace elit21::wallet
