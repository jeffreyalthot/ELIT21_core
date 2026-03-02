#include "interfaces/node.h"

namespace elit21::interfaces {

namespace {
class BasicNode final : public Node {
public:
    std::string Name() const override { return "ELIT21"; }
};
} // namespace

} // namespace elit21::interfaces
