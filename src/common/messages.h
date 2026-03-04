#pragma once

#include <string>

namespace elit21::common {

enum class MessageId {
    kNodeStarting,
    kNodeStopped,
    kInvalidBlock,
};

std::string DefaultMessage(MessageId id);

} // namespace elit21::common
