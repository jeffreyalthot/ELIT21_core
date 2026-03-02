#!/usr/bin/env bash
set -euo pipefail

required_files=(
  "src/ELIT21d.cpp"
  "src/primitives/block.h"
  "src/crypto/hash.cpp"
  "src/consensus/params.cpp"
  "src/kernel/chainstate.cpp"
  "src/node/node.cpp"
  "src/rpc/blockchain.cpp"
  "doc/ARCHITECTURE.md"
)

for file in "${required_files[@]}"; do
  [[ -f "$file" ]] || { echo "Missing: $file"; exit 1; }
done

echo "ELIT21 architecture bootstrap files are in place."
