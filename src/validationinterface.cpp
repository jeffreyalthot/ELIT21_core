#include "validationinterface.h"

namespace elit21 {

void ValidationSignals::Register(ValidationInterface* listener)
{
    if (listener == nullptr) {
        return;
    }

    const auto it = std::find(m_listeners.begin(), m_listeners.end(), listener);
    if (it == m_listeners.end()) {
        m_listeners.push_back(listener);
    }
}

void ValidationSignals::Unregister(ValidationInterface* listener)
{
    m_listeners.erase(std::remove(m_listeners.begin(), m_listeners.end(), listener), m_listeners.end());
}

void ValidationSignals::NotifyBlockTip(const Block& new_tip, std::size_t height) const
{
    for (ValidationInterface* listener : m_listeners) {
        listener->UpdatedBlockTip(new_tip, height);
    }
}

void ValidationSignals::NotifyTransactionAdded(const Transaction& tx) const
{
    for (ValidationInterface* listener : m_listeners) {
        listener->TransactionAddedToMempool(tx);
    }
}

} // namespace elit21
