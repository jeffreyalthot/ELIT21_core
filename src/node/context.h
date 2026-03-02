#ifndef ELIT21_NODE_CONTEXT_H
#define ELIT21_NODE_CONTEXT_H

#include "kernel/chainstate.h"
#include "node/mempool.h"
#include "validationinterface.h"

namespace elit21::node {

struct NodeContext {
    kernel::ChainState* chainstate{nullptr};
    Mempool* mempool{nullptr};
    ValidationSignals* validation_signals{nullptr};
};

} // namespace elit21::node

#endif // ELIT21_NODE_CONTEXT_H
