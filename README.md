# ELIT21 Core

ELIT21 Core est une base de travail pour construire une implémentation blockchain inspirée de Bitcoin Core.

## Statut actuel

- Arborescence initiale du projet créée (proche de Bitcoin Core).
- Seed serveur initial configuré: `elit21.com`.
- Bootstrap de développement C++ commencé dans `src/` avec des modules consensus, kernel, node, mempool, policy, rpc et validation de blocs/transactions.
- Extension de l’architecture avec des fichiers analogues à Bitcoin Core: `chainparams*`, `pow*`, `net_processing*`, `validation*` global et RPC mining.

## Compilation rapide

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Fichiers clés

- `TREE.md`: vue de l'arborescence initiale.
- `config/seeds.json`: configuration seed réseau de départ.
- `doc/ARCHITECTURE.md`: architecture logicielle de la phase bootstrap.
- `src/ELIT21d.cpp`: point d'entrée minimal d'un nœud ELIT21.
- `src/validation/block_validator.cpp`: validation de base (genesis + chaînage bloc-à-bloc).
- `src/validation/validation.cpp`: validation contextuelle (merkle + PoW simplifié).
- `src/chainparams.cpp`: paramètres réseau de plus haut niveau.
- `test/unit/*.cpp`: tests bloc/mempool + nouveaux tests chainparams et merkle/pow.
