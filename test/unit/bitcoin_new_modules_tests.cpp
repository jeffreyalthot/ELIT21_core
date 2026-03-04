#include "net_permissions.h"
#include "node/addrdb.h"
#include "node/blockstorage.h"
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

    return 0;
}
