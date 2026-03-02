#!/usr/bin/env bash
set -euo pipefail

# Génère des fichiers de bootstrap "bitcoin-like" s'ils n'existent pas déjà.
files=(
  src/clientversion.h src/clientversion.cpp
  src/amount.h src/amount.cpp
  src/coins.h src/coins.cpp
  src/checkpoint.h src/checkpoint.cpp
  src/versionbits.h src/versionbits.cpp
  src/deploymentstatus.h src/deploymentstatus.cpp
  src/util/system.h src/util/system.cpp
  src/util/strencodings.h src/util/strencodings.cpp
  src/interfaces/node.h src/interfaces/node.cpp
  src/index/base.h src/index/base.cpp
  src/index/blockfilterindex.h src/index/blockfilterindex.cpp
  src/policy/fees.h src/policy/fees.cpp
  src/policy/rbf.h src/policy/rbf.cpp
  src/node/connection_types.h
  src/node/eviction.h src/node/eviction.cpp
  src/node/txreconciliation.h src/node/txreconciliation.cpp
  src/node/warnings.h src/node/warnings.cpp
  src/node/utxo_snapshot.h src/node/utxo_snapshot.cpp
  src/rpc/net.h src/rpc/net.cpp
  src/rpc/rawtransaction.h src/rpc/rawtransaction.cpp
  src/rpc/server.h src/rpc/server.cpp
  src/rpc/register.h src/rpc/register.cpp
  src/wallet/wallet.h src/wallet/wallet.cpp
)

for file in "${files[@]}"; do
  if [[ -f "$file" ]]; then
    echo "ok: $file"
  else
    mkdir -p "$(dirname "$file")"
    touch "$file"
    echo "created: $file"
  fi
done
