#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>

namespace elit21 {

class CoinsView {
public:
    bool AddUnspent(const std::string& txid, std::uint32_t output_index, const std::string& out);
    std::optional<std::string> GetUnspent(const std::string& txid, std::uint32_t output_index) const;

private:
    std::unordered_map<std::string, std::string> m_utxos;

    static std::string Key(const std::string& txid, std::uint32_t output_index);
};

} // namespace elit21
