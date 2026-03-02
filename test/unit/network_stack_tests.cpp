#include "net.h"
#include "node/blockmanager.h"
#include "node/peerman.h"

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

elit21::Block MakeBlock(const std::string& prev, const std::string& txid)
{
    elit21::Block block;
    block.header.previous_block_hash = prev;
    block.header.merkle_root = "root" + txid;
    block.transactions.push_back(elit21::Transaction{txid, {}, {"miner:50"}});
    return block;
}

} // namespace

int main()
{
    bool ok = true;

    elit21::node::PeerManager peers;
    ok &= Expect(peers.AddPeer("127.0.0.1:21321"), "adds peer");
    ok &= Expect(!peers.AddPeer("127.0.0.1:21321"), "duplicate peer rejected");
    ok &= Expect(peers.IsPeerConnected("127.0.0.1:21321"), "peer is connected");
    ok &= Expect(peers.PeerCount() == 1, "peer count matches");

    elit21::node::BlockManager blocks;
    const elit21::Block genesis = MakeBlock("0", "tx0");
    std::string error;
    ok &= Expect(blocks.AcceptBlock(genesis, error), "accepts first block");
    ok &= Expect(!blocks.AcceptBlock(genesis, error), "rejects duplicate block");
    ok &= Expect(error == "blockmanager.duplicate_block", "duplicate error is explicit");
    ok &= Expect(blocks.StoredBlockCount() == 1, "stored block count matches");

    ok &= Expect(elit21::net::IsKnownCommand("version"), "version command known");
    ok &= Expect(!elit21::net::IsKnownCommand("unknown"), "unknown command rejected");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
