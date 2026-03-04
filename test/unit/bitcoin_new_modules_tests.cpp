#include "common/settings.h"
#include "net_permissions.h"
#include "node/addrdb.h"
#include "node/blockstorage.h"
#include "node/txorphanage.h"
#include "rpc/request.h"
#include "rpc/util.h"

#include <cassert>

int main()
{
    using namespace elit21;

    assert(IsKnownPermission("noban"));
    assert(IsKnownPermission("relay"));
    assert(!IsKnownPermission("invalid"));

    elit21::node::AddrDB addrdb{"data/peers.dat"};
    assert(addrdb.Path() == "data/peers.dat");

    const auto storage_info = elit21::node::GetDefaultBlockStorageInfo();
    assert(storage_info.files_count >= 1);
    assert(storage_info.total_bytes > 0);

    assert(elit21::rpc::NormalizeRpcMethod("GetBlockCount") == "getblockcount");

    elit21::rpc::Request rpc_request{"getblockcount", {}};
    assert(elit21::rpc::IsValidRequest(rpc_request));
    assert(!elit21::rpc::IsValidRequest({"get-block-count", {}}));

    elit21::common::Settings settings;
    settings.Set("chain", "main");
    assert(settings.Has("chain"));
    assert(settings.Get("chain").value_or("") == "main");

    elit21::node::TxOrphanage orphanage;
    assert(orphanage.AddOrphan("tx1", {"parent1"}));
    assert(orphanage.HasOrphan("tx1"));

    const auto ready = orphanage.ResolveByParent("parent1");
    assert(ready.size() == 1);
    assert(ready.front() == "tx1");
    assert(!orphanage.HasOrphan("tx1"));

    return 0;
}
