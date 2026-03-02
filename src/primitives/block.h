#ifndef ELIT21_PRIMITIVES_BLOCK_H
#define ELIT21_PRIMITIVES_BLOCK_H

#include <cstdint>
#include <string>
#include <vector>

namespace elit21 {

struct Transaction {
    std::string txid;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
};

struct BlockHeader {
    std::uint32_t version{1};
    std::string previous_block_hash;
    std::string merkle_root;
    std::uint64_t timestamp{0};
    std::uint32_t bits{0};
    std::uint32_t nonce{0};
};

struct Block {
    BlockHeader header;
    std::vector<Transaction> transactions;
};

} // namespace elit21

#endif // ELIT21_PRIMITIVES_BLOCK_H
