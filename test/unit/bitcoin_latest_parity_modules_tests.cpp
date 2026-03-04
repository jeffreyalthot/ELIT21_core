#include "node/caches.h"
#include "node/kernel_notifications.h"
#include "rpc/client.h"

#include <cstdlib>
#include <vector>

int main()
{
    using elit21::node::ComputeDefaultCaches;
    using elit21::node::KernelNotifications;
    using elit21::rpc::ParseCommandLineRequest;

    const auto caches = ComputeDefaultCaches(128);
    if (caches.block_tree_db_mb == 0 || caches.coins_db_mb == 0 || caches.coins_mb == 0 || caches.mempool_mb == 0) {
        return EXIT_FAILURE;
    }

    KernelNotifications notifications;
    notifications.BlockTipUpdated("abcd");
    notifications.TransactionAdded("tx42");
    if (notifications.Events().size() != 2) {
        return EXIT_FAILURE;
    }

    const std::vector<std::string> argv{"GetBlockChainInfo", "verbose", "1"};
    const auto cmd = ParseCommandLineRequest(argv);
    if (cmd.method != "getblockchaininfo") {
        return EXIT_FAILURE;
    }
    if (cmd.params.size() != 2 || cmd.params[0] != "verbose" || cmd.params[1] != "1") {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
