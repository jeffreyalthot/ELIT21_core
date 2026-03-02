#include "coins.h"

namespace elit21 {

std::string CoinsView::Key(const std::string& txid, const std::uint32_t output_index)
{
    return txid + ':' + std::to_string(output_index);
}

bool CoinsView::AddUnspent(const std::string& txid, const std::uint32_t output_index, const std::string& out)
{
    return m_utxos.emplace(Key(txid, output_index), out).second;
}

std::optional<std::string> CoinsView::GetUnspent(const std::string& txid, const std::uint32_t output_index) const
{
    const auto it = m_utxos.find(Key(txid, output_index));
    if (it == m_utxos.end()) {
        return std::nullopt;
    }
    return it->second;
}

} // namespace elit21
