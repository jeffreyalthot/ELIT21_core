#ifndef ELIT21_VALIDATIONINTERFACE_H
#define ELIT21_VALIDATIONINTERFACE_H

#include "primitives/block.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace elit21 {

class ValidationInterface {
public:
    virtual ~ValidationInterface() = default;

    virtual void UpdatedBlockTip(const Block& /*new_tip*/, std::size_t /*height*/) {}
    virtual void TransactionAddedToMempool(const Transaction& /*tx*/) {}
};

class ValidationSignals {
public:
    void Register(ValidationInterface* listener);
    void Unregister(ValidationInterface* listener);

    void NotifyBlockTip(const Block& new_tip, std::size_t height) const;
    void NotifyTransactionAdded(const Transaction& tx) const;

private:
    std::vector<ValidationInterface*> m_listeners;
};

} // namespace elit21

#endif // ELIT21_VALIDATIONINTERFACE_H
