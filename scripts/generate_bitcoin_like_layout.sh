#!/usr/bin/env bash
set -euo pipefail

# Génère des fichiers de bootstrap "bitcoin-like" s'ils n'existent pas déjà.
files=(
  src/amount.h src/amount.cpp
  src/coins.h src/coins.cpp
  src/checkpoint.h src/checkpoint.cpp
  src/versionbits.h src/versionbits.cpp
  src/deploymentstatus.h src/deploymentstatus.cpp
  src/node/utxo_snapshot.h src/node/utxo_snapshot.cpp
  src/rpc/server.h src/rpc/server.cpp
  src/rpc/register.h src/rpc/register.cpp
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
