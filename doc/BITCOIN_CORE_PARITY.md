# Bitcoin Core parity plan (ELIT21)

Ce document décrit les nouveaux fichiers ajoutés pour rapprocher ELIT21 Core de l'organisation de Bitcoin Core.

## Nouveaux modules bootstrap

- `src/amount.{h,cpp}` : gestion de base des montants (`CAmount`, `MoneyRange`).
- `src/coins.{h,cpp}` : vue UTXO minimale en mémoire.
- `src/checkpoint.{h,cpp}` : validation des checkpoints configurés.
- `src/versionbits.{h,cpp}` : lecture de bits d'activation dans les versions de blocs.
- `src/deploymentstatus.{h,cpp}` : état des déploiements de soft-forks.
- `src/node/utxo_snapshot.{h,cpp}` : métadonnées de snapshot UTXO.
- `src/rpc/server.{h,cpp}` : registre minimal de commandes RPC.
- `src/rpc/register.{h,cpp}` : enregistrement de namespaces RPC.

## Objectif

Recréer une base de fichiers proche de Bitcoin Core tout en gardant une implémentation ELIT21-specific et progressive.
