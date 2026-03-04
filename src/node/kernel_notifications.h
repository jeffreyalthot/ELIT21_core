#ifndef ELIT21_NODE_KERNEL_NOTIFICATIONS_H
#define ELIT21_NODE_KERNEL_NOTIFICATIONS_H

#include <string>
#include <vector>

namespace elit21::node {

class KernelNotifications {
public:
    void BlockTipUpdated(const std::string& block_hash);
    void TransactionAdded(const std::string& txid);

    [[nodiscard]] const std::vector<std::string>& Events() const;

private:
    std::vector<std::string> m_events;
};

} // namespace elit21::node

#endif // ELIT21_NODE_KERNEL_NOTIFICATIONS_H
