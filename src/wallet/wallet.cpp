#include "wallet/wallet.h"

namespace elit21::wallet {

Wallet::Wallet(std::string label) : m_label(std::move(label)) {}

const std::string& Wallet::Label() const
{
    return m_label;
}

} // namespace elit21::wallet
