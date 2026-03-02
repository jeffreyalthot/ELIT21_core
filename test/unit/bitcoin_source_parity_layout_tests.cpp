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

    constexpr std::array<std::string_view, 29> kExpectedFiles = {
        "src/clientversion.h",
        "src/clientversion.cpp",
        "src/util/system.h",
        "src/util/system.cpp",
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
        "src/node/connection_types.h",
        "src/node/eviction.h",
        "src/node/eviction.cpp",
        "src/node/txreconciliation.h",
        "src/node/txreconciliation.cpp",
        "src/node/warnings.h",
        "src/node/warnings.cpp",
        "src/rpc/net.h",
        "src/rpc/net.cpp",
        "src/rpc/rawtransaction.h",
        "src/rpc/rawtransaction.cpp",
        "src/wallet/wallet.h",
        "src/wallet/wallet.cpp",
    };

    for (const auto& expected_file : kExpectedFiles) {
        ok &= ExpectFile(source_root, expected_file);
    }

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
