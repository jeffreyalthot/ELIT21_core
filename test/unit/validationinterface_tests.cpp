#include "init.h"
#include "node/context.h"
#include "validationinterface.h"

#include <cassert>
#include <cstddef>
#include <string>

class Listener final : public elit21::ValidationInterface {
public:
    void UpdatedBlockTip(const elit21::Block& new_tip, std::size_t height) override
    {
        ++tip_notifications;
        last_height = height;
        last_tip_hash = new_tip.header.previous_block_hash;
    }

    void TransactionAddedToMempool(const elit21::Transaction& tx) override
    {
        ++tx_notifications;
        last_txid = tx.txid;
    }

    int tip_notifications{0};
    int tx_notifications{0};
    std::size_t last_height{0};
    std::string last_tip_hash;
    std::string last_txid;
};

int main()
{
    elit21::ValidationSignals signals;
    Listener listener;

    signals.Register(&listener);
    signals.Register(&listener);

    elit21::Block block;
    block.header.previous_block_hash = "prev-hash";

    elit21::Transaction tx;
    tx.txid = "tx-1";

    signals.NotifyBlockTip(block, 42);
    signals.NotifyTransactionAdded(tx);

    assert(listener.tip_notifications == 1);
    assert(listener.tx_notifications == 1);
    assert(listener.last_height == 42);
    assert(listener.last_tip_hash == "prev-hash");
    assert(listener.last_txid == "tx-1");

    signals.Unregister(&listener);
    signals.NotifyTransactionAdded(tx);
    assert(listener.tx_notifications == 1);

    elit21::node::NodeContext empty_context;
    assert(!elit21::AppInitMain(empty_context));

    elit21::kernel::ChainState chainstate;
    elit21::node::Mempool mempool;
    elit21::node::NodeContext ready_context{&chainstate, &mempool, &signals};
    assert(elit21::AppInitMain(ready_context));

    return 0;
}
