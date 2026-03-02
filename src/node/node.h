#ifndef ELIT21_NODE_NODE_H
#define ELIT21_NODE_NODE_H

#include "consensus/params.h"
#include "node/chainman.h"
#include "node/context.h"
#include "node/mempool.h"

#include <string>

namespace elit21::node {

class Node {
public:
    explicit Node(consensus::Params params);

    bool Start();
    bool SubmitBlock(const Block& block);
    bool SubmitTransaction(const Transaction& tx);

    const kernel::ChainState& Chain() const;
    const consensus::Params& Params() const;
    const std::string& LastValidationError() const;
    std::size_t MempoolSize() const;

    NodeContext BuildContext();

private:
    consensus::Params m_params;
    Chainman m_chainman;
    Mempool m_mempool;
    ValidationSignals m_validation_signals;
    bool m_started{false};
    std::string m_last_validation_error;
};

} // namespace elit21::node

#endif // ELIT21_NODE_NODE_H
