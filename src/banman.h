#ifndef ELIT21_BANMAN_H
#define ELIT21_BANMAN_H

#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

namespace elit21 {

class BanMan {
public:
    bool Ban(const std::string& endpoint);
    bool Unban(const std::string& endpoint);
    bool IsBanned(const std::string& endpoint) const;
    std::size_t Count() const;
    std::vector<std::string> Snapshot() const;

private:
    std::unordered_set<std::string> m_banned;
};

} // namespace elit21

#endif // ELIT21_BANMAN_H
