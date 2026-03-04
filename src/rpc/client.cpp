#include "rpc/client.h"

#include "rpc/util.h"

namespace elit21::rpc {

RPCCommand ParseCommandLineRequest(const std::vector<std::string>& argv)
{
    RPCCommand command;
    if (argv.empty()) {
        return command;
    }

    command.method = NormalizeRpcMethod(argv.front());
    for (std::size_t i = 1; i < argv.size(); ++i) {
        command.params.push_back(argv[i]);
    }

    return command;
}

} // namespace elit21::rpc
