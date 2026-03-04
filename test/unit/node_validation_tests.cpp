#include "consensus/params.h"
#include "crypto/hash.h"
#include "node/node.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

std::string ComputeBlockId(const elit21::BlockHeader& header, const std::size_t height)
{
    return elit21::crypto::Hash256(
        std::to_string(header.version) + "|" + header.previous_block_hash + "|" + header.merkle_root + "|" +
        std::to_string(header.timestamp) + "|" + std::to_string(header.bits) + "|" + std::to_string(header.nonce) +
        "|" + std::to_string(height));
}

elit21::Transaction CoinbaseTx(const std::string& txid)
{
    elit21::Transaction tx;
    tx.txid = txid;
    tx.outputs = {"miner:50"};
    return tx;
}

elit21::Block BuildGenesis()
{
    elit21::Block genesis;
    genesis.header.previous_block_hash = "0";
    genesis.header.merkle_root = "root0";
    genesis.header.timestamp = 100;
    genesis.transactions.push_back(CoinbaseTx("tx0"));
    return genesis;
}

elit21::Block BuildNextBlock(const elit21::Block& previous, const std::size_t next_height)
{
    elit21::Block block;
    block.header.previous_block_hash = ComputeBlockId(previous.header, next_height - 1);
    block.header.merkle_root = "root" + std::to_string(next_height);
    block.header.timestamp = previous.header.timestamp + 1;
    block.header.nonce = static_cast<std::uint32_t>(next_height);
    block.transactions.push_back(CoinbaseTx("tx" + std::to_string(next_height)));
    return block;
}

bool Expect(const bool condition, const std::string& message)
{
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
        return false;
    }
    return true;
}

} // namespace

int main()
{
    bool ok = true;

    elit21::node::Node node(elit21::consensus::MainNetParams());

    const elit21::Block genesis = BuildGenesis();
    ok &= Expect(!node.SubmitBlock(genesis), "submit fails while node not started");
    ok &= Expect(node.LastValidationError() == "node.not_started", "captures node.not_started error");

    ok &= Expect(node.Start(), "node starts");
    ok &= Expect(node.SubmitBlock(genesis), "accepts valid genesis");
    ok &= Expect(node.Chain().Height() == 0, "height remains 0 after genesis");

    elit21::Block invalid = BuildNextBlock(genesis, 1);
    invalid.header.previous_block_hash = "bad";
    ok &= Expect(!node.SubmitBlock(invalid), "rejects invalid previous hash");
    ok &= Expect(node.LastValidationError() == "candidate.previous_block_hash_mismatch", "reports hash mismatch");


    elit21::node::Node bootstrap_node(elit21::consensus::MainNetParams());
    ok &= Expect(bootstrap_node.Start(), "bootstrap node starts");
    const elit21::Block remote_block1 = BuildNextBlock(genesis, 1);
    ok &= Expect(bootstrap_node.SubmitBlock(remote_block1), "accepts block when genesis is not transmitted");
    ok &= Expect(bootstrap_node.Chain().Height() == 1, "bootstrap chain height is 1 after first received block");

    const elit21::Block block1 = BuildNextBlock(genesis, 1);
    ok &= Expect(node.SubmitBlock(block1), "accepts valid linked block");
    ok &= Expect(node.Chain().Height() == 1, "height increments after valid block");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
