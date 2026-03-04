#include "node/interface_ui.h"

#include <utility>

namespace elit21::node {

void UiInterface::PushMessage(const UiMessageType type, std::string text)
{
    m_messages.push_back(UiMessage{type, std::move(text)});
}

std::optional<UiMessage> UiInterface::PopMessage()
{
    if (m_messages.empty()) {
        return std::nullopt;
    }

    UiMessage message = std::move(m_messages.front());
    m_messages.pop_front();
    return message;
}

std::size_t UiInterface::PendingCount() const
{
    return m_messages.size();
}

} // namespace elit21::node
