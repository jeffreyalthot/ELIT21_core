#include "node/peerman.h"

namespace elit21::node {

bool PeerManager::AddPeer(const std::string& peer_id)
{
    return m_connected_peers.insert(peer_id).second;
}

bool PeerManager::RemovePeer(const std::string& peer_id)
{
    return m_connected_peers.erase(peer_id) == 1;
}

bool PeerManager::IsPeerConnected(const std::string& peer_id) const
{
    return m_connected_peers.find(peer_id) != m_connected_peers.end();
}

std::size_t PeerManager::PeerCount() const
{
    return m_connected_peers.size();
}

} // namespace elit21::node
