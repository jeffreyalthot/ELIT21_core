#include "node/utxo_snapshot.h"

namespace elit21::node {

bool IsSnapshotMetadataValid(const UTXOSnapshotMetadata& metadata)
{
    return !metadata.base_block_hash.empty() && metadata.coins_count > 0;
}

} // namespace elit21::node
