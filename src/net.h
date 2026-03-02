#ifndef ELIT21_NET_H
#define ELIT21_NET_H

#include <string>
#include <vector>

namespace elit21::net {

struct Message {
    std::string command;
    std::string payload;
};

std::vector<std::string> CoreP2PCommands();
bool IsKnownCommand(const std::string& command);

} // namespace elit21::net

#endif // ELIT21_NET_H
