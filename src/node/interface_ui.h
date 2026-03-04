#pragma once

#include <cstddef>
#include <deque>
#include <optional>
#include <string>

namespace elit21::node {

enum class UiMessageType {
    kInfo,
    kWarning,
    kError,
};

struct UiMessage {
    UiMessageType type;
    std::string text;
};

class UiInterface {
public:
    void PushMessage(UiMessageType type, std::string text);
    std::optional<UiMessage> PopMessage();
    [[nodiscard]] std::size_t PendingCount() const;

private:
    std::deque<UiMessage> m_messages;
};

} // namespace elit21::node
