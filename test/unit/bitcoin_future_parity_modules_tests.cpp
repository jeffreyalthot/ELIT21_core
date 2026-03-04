#include "common/configfile.h"
#include "node/blockmanager_opts.h"
#include "rpc/blockchain_util.h"

#include <cassert>

int main()
{
    using namespace elit21;

    const auto maybe_kv = common::ParseConfigLine("  rpcuser = elit21 ");
    assert(maybe_kv.has_value());
    assert(maybe_kv->first == "rpcuser");
    assert(maybe_kv->second == "elit21");

    const auto cfg = common::ParseConfigText("# comment\nport=9333\n testnet = 1 \n");
    assert(cfg.at("port") == "9333");
    assert(cfg.at("testnet") == "1");

    node::BlockManagerOpts opts;
    assert(node::ValidateBlockManagerOpts(opts));
    assert(node::BuildBlockManagerSummary(opts) == "maxblk=128MB, prune=0MB, fastprune=0");

    opts.max_blockfile_size_mb = 4;
    assert(!node::ValidateBlockManagerOpts(opts));

    opts.max_blockfile_size_mb = 128;
    opts.fast_prune = true;
    assert(!node::ValidateBlockManagerOpts(opts));

    opts.prune_target_mb = 1024;
    assert(node::ValidateBlockManagerOpts(opts));

    assert(rpc::ParseBlockHeight("321").value() == 321);
    assert(!rpc::ParseBlockHeight("-1").has_value());
    assert(!rpc::ParseBlockHeight("abc").has_value());

    assert(rpc::BuildBlockRangeDescriptor(100, 120) == "range:100-120");
    assert(rpc::BuildBlockRangeDescriptor(5, 1) == "invalid");

    return 0;
}
