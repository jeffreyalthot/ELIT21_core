#ifndef ELIT21_CRYPTO_HASH_H
#define ELIT21_CRYPTO_HASH_H

#include <string>

namespace elit21::crypto {

/**
 * Interface hash minimaliste pour la phase de bootstrapping.
 * TODO: Remplacer par une implémentation SHA-256 double proche de Bitcoin.
 */
std::string Hash256(const std::string& data);

} // namespace elit21::crypto

#endif // ELIT21_CRYPTO_HASH_H
