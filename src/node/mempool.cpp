#include "node/mempool.h"

#include "policy/policy.h"
#include "validation/tx_validator.h"

namespace elit21::node {

bool Mempool::Add(const Transaction& tx, std::string& error)
{
    const validation::TxValidationResult validation = validation::ValidateTransaction(tx);
    if (!validation.valid) {
        error = validation.reason;
        return false;
    }

    if (!policy::IsStandardTx(tx)) {
        error = "tx.non_standard";
        return false;
    }

    if (m_known_txids.count(tx.txid) != 0U) {
        error = "tx.duplicate";
        return false;
    }

    m_known_txids.insert(tx.txid);
    m_txs.push_back(tx);
    error.clear();
    return true;
}

std::size_t Mempool::Size() const
{
    return m_txs.size();
}

std::vector<Transaction> Mempool::Snapshot() const
{
    return m_txs;
}

} // namespace elit21::node
