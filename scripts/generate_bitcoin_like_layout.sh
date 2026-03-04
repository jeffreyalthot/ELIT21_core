#!/usr/bin/env bash
set -euo pipefail

# Génère des fichiers de bootstrap "bitcoin-like" s'ils n'existent pas déjà.
files=(
  src/clientversion.h src/clientversion.cpp
  src/logging.h src/logging.cpp
  src/amount.h src/amount.cpp
  src/coins.h src/coins.cpp
  src/checkpoint.h src/checkpoint.cpp
  src/versionbits.h src/versionbits.cpp
  src/deploymentstatus.h src/deploymentstatus.cpp
  src/common/settings.h src/common/settings.cpp
  src/common/messages.h src/common/messages.cpp
  src/kernel/context.h src/kernel/context.cpp
  src/util/system.h src/util/system.cpp
  src/util/time.h src/util/time.cpp
  src/util/strencodings.h src/util/strencodings.cpp
  src/interfaces/node.h src/interfaces/node.cpp
  src/index/base.h src/index/base.cpp
  src/index/blockfilterindex.h src/index/blockfilterindex.cpp
  src/policy/fees.h src/policy/fees.cpp
  src/policy/rbf.h src/policy/rbf.cpp
  src/node/connection_types.h
  src/node/caches.h src/node/caches.cpp
  src/node/kernel_notifications.h src/node/kernel_notifications.cpp
  src/node/txorphanage.h src/node/txorphanage.cpp
  src/node/interface_ui.h src/node/interface_ui.cpp
  src/node/eviction.h src/node/eviction.cpp
  src/node/txreconciliation.h src/node/txreconciliation.cpp
  src/node/warnings.h src/node/warnings.cpp
  src/node/utxo_snapshot.h src/node/utxo_snapshot.cpp
  src/rpc/net.h src/rpc/net.cpp
  src/rpc/client.h src/rpc/client.cpp
  src/rpc/rawtransaction.h src/rpc/rawtransaction.cpp
  src/rpc/request.h src/rpc/request.cpp
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
