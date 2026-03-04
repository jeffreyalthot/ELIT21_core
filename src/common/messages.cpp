#include "common/messages.h"

namespace elit21::common {

std::string DefaultMessage(const MessageId id)
{
    switch (id) {
    case MessageId::kNodeStarting:
        return "ELIT21 node is starting";
    case MessageId::kNodeStopped:
        return "ELIT21 node stopped";
    case MessageId::kInvalidBlock:
        return "Invalid block received";
    }

    return "Unknown message";
}

} // namespace elit21::common
