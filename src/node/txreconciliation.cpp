#include "node/txreconciliation.h"

namespace elit21::node {

std::string BuildTxReconciliationHint(const std::string& peer_id)
{
    return "recon:" + peer_id;
}

} // namespace elit21::node
