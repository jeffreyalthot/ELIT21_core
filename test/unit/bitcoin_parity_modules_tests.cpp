#include "amount.h"
#include "checkpoint.h"
#include "coins.h"
#include "deploymentstatus.h"
#include "node/utxo_snapshot.h"
#include "rpc/register.h"
#include "rpc/server.h"
#include "versionbits.h"

#include <cstdlib>
#include <iostream>

namespace {

bool Expect(bool condition, const char* message)
{
    if (!condition) {
        std::cerr << "Test failed: " << message << '\n';
        return false;
    }
    return true;
}

} // namespace

int main()
{
    bool ok = true;

    ok &= Expect(elit21::MoneyRange(10 * elit21::COIN), "money in range");
    ok &= Expect(!elit21::MoneyRange(elit21::MAX_MONEY + 1), "money out of range");

    elit21::CoinsView view;
    ok &= Expect(view.AddUnspent("tx1", 0, "script:42"), "add utxo");
    ok &= Expect(view.GetUnspent("tx1", 0).has_value(), "read utxo");

    elit21::CheckpointMap checkpoints{{100, "00000100"}};
    ok &= Expect(elit21::IsCheckpointed(checkpoints, 100, "00000100"), "checkpoint match");
    ok &= Expect(!elit21::IsCheckpointed(checkpoints, 100, "00000000"), "checkpoint mismatch");

    ok &= Expect(elit21::IsVersionBitSet(0b1000, 3), "version bit set");
    ok &= Expect(!elit21::IsVersionBitSet(0b1000, 4), "version bit unset");

    elit21::DeploymentStatus status;
    status.Set("taproot", true);
    ok &= Expect(status.IsActive("taproot"), "deployment active");

    elit21::node::UTXOSnapshotMetadata metadata{"abc", 10};
    ok &= Expect(elit21::node::IsSnapshotMetadataValid(metadata), "snapshot metadata valid");

    elit21::rpc::Server server;
    elit21::rpc::RegisterBlockchainRPC(server);
    elit21::rpc::RegisterMiningRPC(server);
    elit21::rpc::RegisterMempoolRPC(server);
    ok &= Expect(server.Call("getblockchaininfo", "").has_value(), "blockchain rpc registered");
    ok &= Expect(server.Call("getmininginfo", "").has_value(), "mining rpc registered");
    ok &= Expect(server.Call("getmempoolinfo", "").has_value(), "mempool rpc registered");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
