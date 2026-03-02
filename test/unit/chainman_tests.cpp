#include "node/chainman.h"

#include "crypto/hash.h"

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

    elit21::node::Chainman chainman;
    std::string error;

    const elit21::Block genesis = BuildGenesis();
    ok &= Expect(chainman.AcceptBlock(genesis, error), "accepts valid genesis");
    ok &= Expect(chainman.ActiveChain().Height() == 0, "height is 0 after genesis");

    elit21::Block invalid = BuildNextBlock(genesis, 1);
    invalid.header.previous_block_hash = "bad";
    ok &= Expect(!chainman.AcceptBlock(invalid, error), "rejects invalid block link");
    ok &= Expect(error == "candidate.previous_block_hash_mismatch", "sets detailed validation error");

    const elit21::Block block1 = BuildNextBlock(genesis, 1);
    ok &= Expect(chainman.AcceptBlock(block1, error), "accepts valid next block");
    ok &= Expect(chainman.ActiveChain().Height() == 1, "height is 1 after second block");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
