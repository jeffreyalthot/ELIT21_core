#include "node/addrdb.h"

#include <utility>

namespace elit21::node {

AddrDB::AddrDB(std::string path)
    : m_path(std::move(path))
{
}

const std::string& AddrDB::Path() const
{
    return m_path;
}

} // namespace elit21::node
