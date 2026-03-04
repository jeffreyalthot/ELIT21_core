#include "kernel/context.h"

namespace elit21::kernel {

void Context::AttachChainstate(std::shared_ptr<Chainstate> chainstate)
{
    m_chainstate = std::move(chainstate);
}

std::shared_ptr<Chainstate> Context::ActiveChainstate() const
{
    return m_chainstate;
}

} // namespace elit21::kernel
