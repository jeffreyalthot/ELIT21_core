#include "node/warnings.h"

namespace elit21::node {

void Warnings::Set(const std::string& warning)
{
    m_warning = warning;
}

std::optional<std::string> Warnings::Get() const
{
    return m_warning;
}

} // namespace elit21::node
