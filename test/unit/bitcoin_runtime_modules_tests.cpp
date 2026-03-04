#include "logging.h"
#include "node/blockmanager_args.h"
#include "node/chainstate.h"
#include "util/time.h"
#include "validation.h"

#include "kernel/chainstate.h"
#include "primitives/block.h"

#include <cassert>

int main()
{
    elit21::Logger logger;
    logger.Enable(elit21::LogCategory::kNet);

    logger.Log(elit21::LogCategory::kRpc, "ignored");
    assert(logger.Entries().empty());

    logger.Log(elit21::LogCategory::kNet, "peer connected");
    assert(logger.Entries().size() == 1);

    const auto last = logger.Last();
    assert(last.has_value());
    assert(last->find("[net]") == 0);

    const auto timestamp = elit21::util::GetTimeSeconds();
    const auto formatted = elit21::util::FormatISO8601(timestamp);
    assert(formatted.size() == 20);
    assert(formatted[4] == '-');
    assert(formatted[10] == 'T');
    assert(formatted.back() == 'Z');

    elit21::node::BlockManagerArgs block_args{};
    assert(elit21::node::IsValidBlockManagerArgs(block_args));

    elit21::kernel::ChainState chainstate;
    elit21::Block genesis{{1, "0", "merkle", 1, 0x1d00ffff, 0}, {{"genesis-tx", {"coinbase"}, {"50"}}}};
    assert(chainstate.AddBlock(genesis));

    const auto stats = elit21::node::SnapshotChainstate(chainstate);
    assert(stats.has_tip);
    assert(stats.height == 0);

    const auto genesis_validation = elit21::ValidateBlockForChain(nullptr, genesis, 0);
    assert(genesis_validation.valid);

    const elit21::Transaction tx{"tx-runtime", {"in"}, {"out"}};
    assert(elit21::ValidateTransactionStandard(tx).valid);

    return 0;
}
