#pragma once

#include <string>
#include <vector>

namespace elit21 {

struct DeploymentInfo {
    std::string name;
    bool active{false};
};

class DeploymentStatus {
public:
    void Set(const std::string& name, bool active);
    bool IsActive(const std::string& name) const;
    std::vector<DeploymentInfo> Snapshot() const;

private:
    std::vector<DeploymentInfo> m_deployments;
};

} // namespace elit21
