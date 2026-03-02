# Architecture de démarrage ELIT21 Core

Cette première base relie les principaux sous-systèmes afin de démarrer le développement.

## Modules initialisés

- `src/primitives/`: structures `Transaction`, `BlockHeader`, `Block`.
- `src/crypto/`: interface de hash + placeholder `Hash256`.
- `src/consensus/`: paramètres réseau (`main`, `test`).
- `src/kernel/`: `ChainState` en mémoire.
- `src/node/`: orchestration du cycle de vie d'un nœud.
- `src/interfaces/`: contrat minimal d'accès à la chaîne.
- `src/rpc/`: point d'entrée `GetBlockchainInfo`.
- `src/ELIT21d.cpp`: exécutable de démarrage local.

## Étapes suivantes recommandées

1. Ajouter CMake + targets pour compiler les modules.
2. Remplacer le hash placeholder par SHA-256 double.
3. Implémenter la validation de blocs (header, preuve de travail, transactions).
4. Ajouter des tests unitaires de consensus et kernel.
