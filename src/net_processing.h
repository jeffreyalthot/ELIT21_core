#ifndef ELIT21_NET_PROCESSING_H
#define ELIT21_NET_PROCESSING_H

#include "node/node.h"

#include <string>

namespace elit21::net {

bool ProcessNewBlock(node::Node& node, const Block& block, std::string& error);

} // namespace elit21::net

#endif // ELIT21_NET_PROCESSING_H
