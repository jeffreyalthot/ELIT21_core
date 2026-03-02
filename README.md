# ELIT21 Core

ELIT21 Core est une base de travail pour construire une implémentation blockchain inspirée de Bitcoin Core.

## Statut actuel

- Arborescence initiale du projet créée (proche de Bitcoin Core).
- Seed serveur initial configuré: `elit21.com`.
- Bootstrap de développement C++ commencé dans `src/` avec des modules consensus, kernel, node, rpc et validation de blocs.
- Build CMake minimal + premier test unitaire du flux de validation.

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
- `test/unit/node_validation_tests.cpp`: tests de soumission et validation de blocs.
