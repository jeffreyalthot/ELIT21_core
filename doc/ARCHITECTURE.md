# Architecture de démarrage ELIT21 Core

Cette première base relie les principaux sous-systèmes afin de démarrer le développement.

## Modules initialisés

- `src/primitives/`: structures `Transaction`, `BlockHeader`, `Block`.
- `src/crypto/`: interface de hash + placeholder `Hash256`.
- `src/consensus/`: paramètres réseau (`main`, `test`) + calcul de merkle root.
- `src/kernel/`: `ChainState` en mémoire.
- `src/node/`: orchestration du cycle de vie d'un nœud + soumission de blocs.
- `src/validation/`: règles de validation minimales + validation contextuelle.
- `src/interfaces/`: contrat minimal d'accès à la chaîne.
- `src/rpc/`: points d'entrée `GetBlockchainInfo`, `GetMempoolInfo` et `GetMiningInfo`.
- `src/policy/`: règles de policy standard pour l'admission mempool.
- `src/chainparams*`: agrégation des paramètres réseau (consensus + base).
- `src/pow*`: vérification PoW simplifiée.
- `src/net_processing*`: couche de traitement bloc côté réseau.
- `src/ELIT21d.cpp`: exécutable de démarrage local.

## Flux de validation actuel

1. `Node::Start()` active le nœud.
2. `Node::SubmitBlock()` refuse toute soumission si le nœud n'est pas démarré.
3. Premier bloc: validation genesis (`previous_block_hash == "0"`, merkle root présent, transactions non vides).
4. Blocs suivants: validation de lien avec le bloc précédent (hash attendu, timestamp monotone, transactions non vides).
5. Validation contextuelle additionnelle disponible via `ContextualCheckBlock()`:
   - transactions présentes,
   - merkle root cohérente,
   - PoW simplifiée conforme.
6. Si la validation réussit, le bloc est ajouté à `ChainState`.

## Build et tests

- `CMakeLists.txt` définit:
  - la librairie `elit21_core`.
  - l'exécutable `ELIT21d`.
  - les tests `node_validation_tests`, `mempool_policy_tests`, `chainparams_tests`, `merkle_pow_tests`.

## Étapes suivantes recommandées

1. Remplacer le hash placeholder par SHA-256 double.
2. Implémenter une vraie racine de Merkle à partir des transactions sérialisées.
3. Ajouter la validation complète d'en-tête (bits/PoW) et la difficulté.
4. Étendre les tests unitaires consensus/kernel/rpc/net.
5. Préparer les fichiers de configuration runtime (`bitcoin.conf`-like pour ELIT21).
