# Arborescence ELIT21 Core (inspirée de Bitcoin Core)

Cette première étape recrée une arborescence de base similaire à Bitcoin Core pour poser les fondations du projet.

## Dossiers racine

- `.github/`
- `build-aux/`
- `ci/`
- `cmake/`
- `config/`
- `contrib/`
- `depends/`
- `doc/`
- `share/`
- `src/`
- `test/`

## Seed serveur

Le seed serveur principal configuré pour démarrer le réseau est:

- `elit21.com`

Voir `config/seeds.json`.

## Bootstrap code ajouté

- `src/ELIT21d.cpp` : démarrage minimal d'un nœud.
- `src/primitives/block.h` : structures bloc/transaction.
- `src/crypto/hash.{h,cpp}` : interface hash + placeholder.
- `src/consensus/params.{h,cpp}` : paramètres réseau initiaux.
- `src/kernel/chainstate.{h,cpp}` : état de chaîne en mémoire.
- `src/node/node.{h,cpp}` : cycle de vie du nœud.
- `src/rpc/blockchain.{h,cpp}` : endpoint d'information blockchain.
- `doc/ARCHITECTURE.md` : documentation de l'architecture bootstrap.

## Fichiers de bootstrap ajoutés (phase 2)

- `src/node/mempool.{h,cpp}` : mempool en mémoire (anti-doublon txid).
- `src/validation/tx_validator.{h,cpp}` : validation transaction minimale.
- `src/policy/policy.{h,cpp}` : policy de transaction standard.
- `src/rpc/mempool.{h,cpp}` : endpoint d'information mempool.
- `test/unit/mempool_policy_tests.cpp` : tests d'acceptation transaction.
