#ifndef ELIT21_POW_H
#define ELIT21_POW_H

#include "primitives/block.h"

namespace elit21::pow {

bool CheckProofOfWork(const BlockHeader& header);

} // namespace elit21::pow

#endif // ELIT21_POW_H
