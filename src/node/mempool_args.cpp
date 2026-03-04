#include "node/mempool_args.h"

namespace elit21::node {

bool ValidateMempoolArgs(const MempoolArgs& args)
{
    return args.max_mempool_mb > 0 && args.expiry_hours > 0;
}

std::string BuildMempoolArgsSummary(const MempoolArgs& args)
{
    return "max=" + std::to_string(args.max_mempool_mb) + "MB, expiry=" +
           std::to_string(args.expiry_hours) + "h, persist=" + (args.persist ? "1" : "0");
}

} // namespace elit21::node
