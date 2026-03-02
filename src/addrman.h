#ifndef ELIT21_ADDRMAN_H
#define ELIT21_ADDRMAN_H

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

namespace elit21 {

class AddrMan {
public:
    bool Add(const std::string& endpoint);
    bool MarkGood(const std::string& endpoint);
    bool IsKnown(const std::string& endpoint) const;
    std::size_t Size() const;
    std::vector<std::string> GetAll() const;

private:
    struct Entry {
        bool is_good{false};
    };

    std::unordered_map<std::string, Entry> m_entries;
};

} // namespace elit21

#endif // ELIT21_ADDRMAN_H
