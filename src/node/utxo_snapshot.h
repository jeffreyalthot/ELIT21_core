#pragma once

#include <cstdint>
#include <string>

namespace elit21::node {

struct UTXOSnapshotMetadata {
    std::string base_block_hash;
    std::uint64_t coins_count{0};
};

bool IsSnapshotMetadataValid(const UTXOSnapshotMetadata& metadata);

} // namespace elit21::node
