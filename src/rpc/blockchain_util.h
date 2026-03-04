#ifndef ELIT21_RPC_BLOCKCHAIN_UTIL_H
#define ELIT21_RPC_BLOCKCHAIN_UTIL_H

#include <optional>
#include <string>

namespace elit21::rpc {

std::optional<int> ParseBlockHeight(const std::string& value);
std::string BuildBlockRangeDescriptor(int start_height, int end_height);

} // namespace elit21::rpc

#endif // ELIT21_RPC_BLOCKCHAIN_UTIL_H
