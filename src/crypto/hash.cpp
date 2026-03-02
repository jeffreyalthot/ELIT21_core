#include "crypto/hash.h"

#include <functional>
#include <sstream>

namespace elit21::crypto {

std::string Hash256(const std::string& data)
{
    // Placeholder de démarrage: pas cryptographiquement sûr.
    const std::size_t h1 = std::hash<std::string>{}(data);
    const std::size_t h2 = std::hash<std::string>{}(std::to_string(h1) + data);

    std::ostringstream out;
    out << std::hex << h1 << h2;
    return out.str();
}

} // namespace elit21::crypto
