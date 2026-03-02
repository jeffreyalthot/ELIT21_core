#include "index/base.h"

namespace elit21::index {

BaseIndex::BaseIndex(std::string name) : m_name(std::move(name)) {}

const std::string& BaseIndex::Name() const
{
    return m_name;
}

} // namespace elit21::index
