#include "deploymentstatus.h"

namespace elit21 {

void DeploymentStatus::Set(const std::string& name, const bool active)
{
    for (auto& deployment : m_deployments) {
        if (deployment.name == name) {
            deployment.active = active;
            return;
        }
    }
    m_deployments.push_back({name, active});
}

bool DeploymentStatus::IsActive(const std::string& name) const
{
    for (const auto& deployment : m_deployments) {
        if (deployment.name == name) {
            return deployment.active;
        }
    }
    return false;
}

std::vector<DeploymentInfo> DeploymentStatus::Snapshot() const
{
    return m_deployments;
}

} // namespace elit21
