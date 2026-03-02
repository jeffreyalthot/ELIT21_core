#include "consensus/params.h"

namespace elit21::consensus {

Params MainNetParams()
{
    return Params{"main", 600, 2016, 50};
}

Params TestNetParams()
{
    return Params{"test", 120, 144, 50};
}

} // namespace elit21::consensus
