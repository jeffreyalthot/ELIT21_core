#ifndef ELIT21_NODE_PEERMAN_H
#define ELIT21_NODE_PEERMAN_H

#include <cstddef>
#include <string>
#include <unordered_set>

namespace elit21::node {

class PeerManager {
public:
    bool AddPeer(const std::string& peer_id);
    bool RemovePeer(const std::string& peer_id);
    bool IsPeerConnected(const std::string& peer_id) const;
    std::size_t PeerCount() const;

private:
    std::unordered_set<std::string> m_connected_peers;
};

} // namespace elit21::node

#endif // ELIT21_NODE_PEERMAN_H
