#pragma once

#include <string>

namespace elit21::node {

constexpr int kProtocolVersion = 70016;
constexpr int kMinPeerProtocolVersion = 70001;

[[nodiscard]] std::string BuildUserAgent(const std::string& node_name, const std::string& version);

} // namespace elit21::node
