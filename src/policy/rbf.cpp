#include "policy/rbf.h"

namespace elit21::policy {

bool SignalsOptInRBF(const unsigned int sequence)
{
    return sequence < 0xFFFFFFFEU;
}

} // namespace elit21::policy
