#include "versionbits.h"

namespace elit21 {

bool IsVersionBitSet(const std::uint32_t version, const std::uint32_t bit)
{
    if (bit >= 32) {
        return false;
    }
    return (version & (1U << bit)) != 0;
}

} // namespace elit21
