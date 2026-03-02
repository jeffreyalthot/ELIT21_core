#include "consensus/merkle.h"
#include "pow.h"
#include "primitives/block.h"

#include <cassert>

int main()
{
    using elit21::Transaction;

    const std::vector<Transaction> txs{
        Transaction{"tx1", {"in1"}, {"out1"}},
        Transaction{"tx2", {"in2"}, {"out2"}},
        Transaction{"tx3", {"in3"}, {"out3"}}
    };

    const std::string merkle = elit21::consensus::ComputeMerkleRoot(txs);
    assert(!merkle.empty());

    elit21::BlockHeader header;
    header.previous_block_hash = "abc";
    header.merkle_root = merkle;
    header.timestamp = 123456;
    header.bits = 0;
    header.nonce = 1;

    assert(!elit21::pow::CheckProofOfWork(header));

    return 0;
}
