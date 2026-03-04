#ifndef ELIT21_NODE_TXORPHANAGE_H
#define ELIT21_NODE_TXORPHANAGE_H

#include <cstddef>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace elit21::node {

class TxOrphanage {
public:
    bool AddOrphan(std::string txid, std::vector<std::string> missing_parents);
    bool HasOrphan(const std::string& txid) const;
    std::size_t OrphanCount() const;
    std::vector<std::string> ResolveByParent(const std::string& parent_txid);

private:
    struct OrphanEntry {
        std::vector<std::string> missing_parents;
    };

    std::unordered_map<std::string, OrphanEntry> m_orphans;
    std::unordered_map<std::string, std::unordered_set<std::string>> m_waiting_by_parent;
};

} // namespace elit21::node

#endif // ELIT21_NODE_TXORPHANAGE_H
