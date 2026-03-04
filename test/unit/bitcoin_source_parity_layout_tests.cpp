#include <array>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string_view>

namespace {

bool ExpectFile(const std::filesystem::path& root, const std::string_view relative_path)
{
    const auto full_path = root / relative_path;
    if (!std::filesystem::exists(full_path)) {
        std::cerr << "Missing expected file: " << full_path << '\n';
        return false;
    }
    return true;
}

} // namespace

int main()
{
    namespace fs = std::filesystem;

    bool ok = true;
    const fs::path source_root{PROJECT_SOURCE_DIR};

    constexpr std::array<std::string_view, 75> kExpectedFiles = {
        "src/clientversion.h",
        "src/clientversion.cpp",
        "src/logging.h",
        "src/logging.cpp",
        "src/common/messages.h",
        "src/common/messages.cpp",
        "src/common/init.h",
        "src/common/init.cpp",
        "src/common/url.h",
        "src/common/url.cpp",
        "src/node/database_args.h",
        "src/node/database_args.cpp",
        "src/node/types.h",
        "src/node/types.cpp",
        "src/node/mempool_args.h",
        "src/node/mempool_args.cpp",
        "src/node/caches.h",
        "src/node/caches.cpp",
        "src/node/kernel_notifications.h",
        "src/node/kernel_notifications.cpp",
        "src/rpc/server_util.h",
        "src/rpc/server_util.cpp",
        "src/rpc/client.h",
        "src/rpc/client.cpp",
        "src/rpc/protocol.h",
        "src/rpc/protocol.cpp",
        "src/util/system.h",
        "src/util/system.cpp",
        "src/util/time.h",
        "src/util/time.cpp",
        "src/util/strencodings.h",
        "src/util/strencodings.cpp",
        "src/interfaces/node.h",
        "src/interfaces/node.cpp",
        "src/index/base.h",
        "src/index/base.cpp",
        "src/index/blockfilterindex.h",
        "src/index/blockfilterindex.cpp",
        "src/policy/fees.h",
        "src/policy/fees.cpp",
        "src/policy/rbf.h",
        "src/policy/rbf.cpp",
        "src/net_permissions.h",
        "src/net_permissions.cpp",
        "src/validation.h",
        "src/validation.cpp",
        "src/node/addrdb.h",
        "src/node/addrdb.cpp",
        "src/node/blockmanager_args.h",
        "src/node/blockmanager_args.cpp",
        "src/node/chainstate.h",
        "src/node/chainstate.cpp",
        "src/node/connection_types.h",
        "src/node/txorphanage.h",
        "src/node/txorphanage.cpp",
        "src/node/interface_ui.h",
        "src/node/interface_ui.cpp",
        "src/node/blockstorage.h",
        "src/node/blockstorage.cpp",
        "src/node/eviction.h",
        "src/node/eviction.cpp",
        "src/node/txreconciliation.h",
        "src/node/txreconciliation.cpp",
        "src/node/warnings.h",
        "src/node/warnings.cpp",
        "src/rpc/net.h",
        "src/rpc/net.cpp",
        "src/rpc/util.h",
        "src/rpc/util.cpp",
        "src/rpc/rawtransaction.h",
        "src/rpc/rawtransaction.cpp",
        "src/rpc/request.h",
        "src/rpc/request.cpp",
        "src/wallet/wallet.h",
        "src/wallet/wallet.cpp",
    };

    for (const auto& expected_file : kExpectedFiles) {
        ok &= ExpectFile(source_root, expected_file);
    }

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
