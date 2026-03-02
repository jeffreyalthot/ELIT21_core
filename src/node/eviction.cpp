#include "node/eviction.h"

namespace elit21::node {

bool ShouldEvictPeer(const int misbehavior_score)
{
    return misbehavior_score >= 100;
}

} // namespace elit21::node
