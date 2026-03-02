#include "node/node.h"
#include "consensus/params.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

bool Expect(const bool condition, const std::string& message)
{
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
        return false;
    }
    return true;
}

elit21::Transaction BuildTx(const std::string& txid, const std::size_t outputs)
{
    elit21::Transaction tx;
    tx.txid = txid;
    tx.inputs = {"prevout:0"};
    tx.outputs.assign(outputs, "user:1");
    return tx;
}

} // namespace

int main()
{
    bool ok = true;

    elit21::node::Node node(elit21::consensus::MainNetParams());

    const elit21::Transaction valid = BuildTx("mempool-tx-1", 2);
    ok &= Expect(!node.SubmitTransaction(valid), "submit tx fails before node start");
    ok &= Expect(node.LastValidationError() == "node.not_started", "captures node.not_started for tx");

    ok &= Expect(node.Start(), "node starts for mempool tests");
    ok &= Expect(node.SubmitTransaction(valid), "accepts standard transaction");
    ok &= Expect(node.MempoolSize() == 1, "mempool size increments after valid tx");

    ok &= Expect(!node.SubmitTransaction(valid), "rejects duplicate transaction");
    ok &= Expect(node.LastValidationError() == "tx.duplicate", "reports duplicate tx");

    const elit21::Transaction non_standard = BuildTx("mempool-tx-2", 5);
    ok &= Expect(!node.SubmitTransaction(non_standard), "rejects non-standard transaction");
    ok &= Expect(node.LastValidationError() == "tx.non_standard", "reports non-standard tx");

    elit21::Transaction empty_tx;
    empty_tx.outputs = {"user:1"};
    ok &= Expect(!node.SubmitTransaction(empty_tx), "rejects tx with empty txid");
    ok &= Expect(node.LastValidationError() == "tx.txid_empty", "reports empty txid");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
