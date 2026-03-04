#include "node/blockstorage.h"

namespace elit21::node {

BlockStorageInfo GetDefaultBlockStorageInfo()
{
    return BlockStorageInfo{1, 128 * 1024};
}

} // namespace elit21::node
