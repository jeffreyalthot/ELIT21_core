#include "common/init.h"
#include "node/database_args.h"
#include "node/types.h"
#include "rpc/server_util.h"

#include <cassert>

int main()
{
    using namespace elit21;

    common::InitConfig config;
    assert(common::IsSupportedNetwork(config.network));
    assert(common::IsDataDirConfigured(config));
    assert(!common::IsSupportedNetwork("devnet"));

    node::DatabaseArgs db_args;
    assert(node::BuildBlocksPath("/tmp/elit21", db_args) == "/tmp/elit21/blocks");
    assert(node::BuildChainstatePath("/tmp/elit21", db_args) == "/tmp/elit21/chainstate");

    assert(node::kProtocolVersion >= node::kMinPeerProtocolVersion);
    assert(node::BuildUserAgent("ELIT21", "0.1.0") == "/ELIT21:0.1.0/");

    const auto timeout = rpc::ParseRpcTimeoutSeconds("15");
    assert(timeout.has_value());
    assert(timeout.value() == 15);
    assert(!rpc::ParseRpcTimeoutSeconds("-1").has_value());
    assert(!rpc::ParseRpcTimeoutSeconds("abc").has_value());
    assert(rpc::FormatRpcError(-1, "invalid request") == "{\"code\":-1,\"message\":\"invalid request\"}");

    return 0;
}
