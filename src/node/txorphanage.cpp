#include "node/txorphanage.h"

#include <algorithm>

namespace elit21::node {

bool TxOrphanage::AddOrphan(std::string txid, std::vector<std::string> missing_parents)
{
    if (txid.empty() || missing_parents.empty()) {
        return false;
    }

    const auto [it, inserted] = m_orphans.emplace(txid, OrphanEntry{std::move(missing_parents)});
    if (!inserted) {
        return false;
    }

    for (const auto& parent : it->second.missing_parents) {
        m_waiting_by_parent[parent].insert(it->first);
    }

    return true;
}

bool TxOrphanage::HasOrphan(const std::string& txid) const
{
    return m_orphans.find(txid) != m_orphans.end();
}

std::size_t TxOrphanage::OrphanCount() const
{
    return m_orphans.size();
}

std::vector<std::string> TxOrphanage::ResolveByParent(const std::string& parent_txid)
{
    std::vector<std::string> ready;
    const auto waiting_it = m_waiting_by_parent.find(parent_txid);
    if (waiting_it == m_waiting_by_parent.end()) {
        return ready;
    }

    for (const auto& orphan_txid : waiting_it->second) {
        auto orphan_it = m_orphans.find(orphan_txid);
        if (orphan_it == m_orphans.end()) {
            continue;
        }

        auto& parents = orphan_it->second.missing_parents;
        parents.erase(std::remove(parents.begin(), parents.end(), parent_txid), parents.end());
        if (parents.empty()) {
            ready.push_back(orphan_txid);
            m_orphans.erase(orphan_it);
        }
    }

    m_waiting_by_parent.erase(waiting_it);
    return ready;
}

} // namespace elit21::node
