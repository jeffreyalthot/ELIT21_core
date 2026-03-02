#include "rpc/rawtransaction.h"

namespace elit21::rpc {

std::string DecodeRawTransaction(const std::string& raw_tx)
{
    return "decoded:" + raw_tx;
}

} // namespace elit21::rpc
