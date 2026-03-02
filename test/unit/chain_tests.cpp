#include "chain.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

elit21::Block MakeBlock(const std::string& prev_hash, const std::string& merkle, std::uint64_t timestamp)
{
    elit21::Block block;
    block.header.previous_block_hash = prev_hash;
    block.header.merkle_root = merkle;
    block.header.timestamp = timestamp;
    block.transactions.push_back({"tx", {}, {"out"}});
    return block;
}

bool Expect(bool condition, const std::string& message)
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

    elit21::Chain chain;

    const elit21::Block genesis = MakeBlock("0", "root0", 100);
    ok &= Expect(chain.SetTip(genesis), "set genesis tip");
    ok &= Expect(chain.Height() == 0, "genesis height is 0");

    const std::string genesis_hash = elit21::ComputeBlockHash(genesis.header, 0);
    ok &= Expect(chain.Contains(genesis_hash), "chain contains genesis hash");

    const elit21::Block block1 = MakeBlock(genesis_hash, "root1", 101);
    ok &= Expect(chain.SetTip(block1), "set height 1 tip");
    ok &= Expect(chain.Height() == 1, "height becomes 1");

    const elit21::Block bad = MakeBlock("bad_prev", "root2", 102);
    ok &= Expect(!chain.SetTip(bad), "reject mismatched previous hash");

    const elit21::BlockIndex* index0 = chain.AtHeight(0);
    ok &= Expect(index0 != nullptr && index0->block_hash == genesis_hash, "height 0 index available");

    const elit21::BlockIndex* tip = chain.Tip();
    const std::string block1_hash = elit21::ComputeBlockHash(block1.header, 1);
    ok &= Expect(tip != nullptr && tip->block_hash == block1_hash, "tip index matches block1 hash");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
