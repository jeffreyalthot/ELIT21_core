#ifndef ELIT21_NODE_CACHES_H
#define ELIT21_NODE_CACHES_H

#include <cstddef>

namespace elit21::node {

struct CacheSizes {
    std::size_t block_tree_db_mb{0};
    std::size_t coins_db_mb{0};
    std::size_t coins_mb{0};
    std::size_t mempool_mb{0};
};

CacheSizes ComputeDefaultCaches(std::size_t total_cache_mb);

} // namespace elit21::node

#endif // ELIT21_NODE_CACHES_H
