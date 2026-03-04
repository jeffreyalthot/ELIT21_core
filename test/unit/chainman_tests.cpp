#include "node/chainman.h"

#include "chain.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

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
    block.header.previous_block_hash = elit21::ComputeBlockHash(previous.header, next_height - 1);
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


    elit21::node::Chainman bootstrap_chainman;
    const elit21::Block remote_block1 = BuildNextBlock(genesis, 1);
    ok &= Expect(bootstrap_chainman.AcceptBlock(remote_block1, error), "accepts block when genesis is missing from network");
    ok &= Expect(bootstrap_chainman.ActiveChain().Height() == 1, "height is 1 after local genesis bootstrap");
    ok &= Expect(
        bootstrap_chainman.ActiveChain().HasBlock(remote_block1.header.previous_block_hash),
        "chainstate stores assumed genesis hash");

    const elit21::Block block1 = BuildNextBlock(genesis, 1);
    ok &= Expect(chainman.AcceptBlock(block1, error), "accepts valid next block");
    ok &= Expect(chainman.ActiveChain().Height() == 1, "height is 1 after second block");
    ok &= Expect(
        chainman.ActiveChain().HasBlock(elit21::ComputeBlockHash(block1.header, 1)),
        "chainstate contains second block hash");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
