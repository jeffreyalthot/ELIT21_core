#include "node/kernel_notifications.h"

namespace elit21::node {

void KernelNotifications::BlockTipUpdated(const std::string& block_hash)
{
    m_events.push_back("block-tip:" + block_hash);
}

void KernelNotifications::TransactionAdded(const std::string& txid)
{
    m_events.push_back("tx-added:" + txid);
}

const std::vector<std::string>& KernelNotifications::Events() const
{
    return m_events;
}

} // namespace elit21::node
