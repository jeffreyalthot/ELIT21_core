#ifndef ELIT21_KERNEL_CONTEXT_H
#define ELIT21_KERNEL_CONTEXT_H

#include <memory>

namespace elit21 {
class Chainstate;
}

namespace elit21::kernel {

class Context {
public:
    void AttachChainstate(std::shared_ptr<Chainstate> chainstate);
    std::shared_ptr<Chainstate> ActiveChainstate() const;

private:
    std::shared_ptr<Chainstate> m_chainstate;
};

} // namespace elit21::kernel

#endif // ELIT21_KERNEL_CONTEXT_H
