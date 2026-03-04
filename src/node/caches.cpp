#include "node/caches.h"

#include <algorithm>

namespace elit21::node {

CacheSizes ComputeDefaultCaches(const std::size_t total_cache_mb)
{
    // Répartition inspirée des rôles de cache de Bitcoin Core,
    // adaptée à un bootstrap ELIT21 minimal.
    const std::size_t safe_total = std::max<std::size_t>(total_cache_mb, 4U);

    CacheSizes caches;
    caches.block_tree_db_mb = std::max<std::size_t>(safe_total / 8U, 1U);
    caches.coins_db_mb = std::max<std::size_t>(safe_total / 4U, 1U);
    caches.coins_mb = std::max<std::size_t>(safe_total / 2U, 1U);

    const std::size_t used = caches.block_tree_db_mb + caches.coins_db_mb + caches.coins_mb;
    caches.mempool_mb = used < safe_total ? safe_total - used : 1U;

    return caches;
}

} // namespace elit21::node
