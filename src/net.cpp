#include "net.h"

#include <algorithm>

namespace elit21::net {

std::vector<std::string> CoreP2PCommands()
{
    return {
        "version",
        "verack",
        "ping",
        "pong",
        "inv",
        "getdata",
        "headers",
        "block",
        "tx",
    };
}

bool IsKnownCommand(const std::string& command)
{
    const std::vector<std::string> commands = CoreP2PCommands();
    return std::find(commands.cbegin(), commands.cend(), command) != commands.cend();
}

} // namespace elit21::net
