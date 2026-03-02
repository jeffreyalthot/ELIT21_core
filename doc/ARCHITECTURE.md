# Architecture de démarrage ELIT21 Core

Cette première base relie les principaux sous-systèmes afin de démarrer le développement.

## Modules initialisés

- `src/primitives/`: structures `Transaction`, `BlockHeader`, `Block`.
- `src/crypto/`: interface de hash + placeholder `Hash256`.
- `src/consensus/`: paramètres réseau (`main`, `test`).
- `src/kernel/`: `ChainState` en mémoire.
- `src/node/`: orchestration du cycle de vie d'un nœud + soumission de blocs.
- `src/validation/`: règles de validation minimales (bloc genesis, chaînage et transactions).
- `src/interfaces/`: contrat minimal d'accès à la chaîne.
- `src/rpc/`: points d'entrée `GetBlockchainInfo` et `GetMempoolInfo`.
- `src/policy/`: règles de policy standard pour l'admission mempool.
- `src/ELIT21d.cpp`: exécutable de démarrage local.

## Flux de validation actuel

1. `Node::Start()` active le nœud.
2. `Node::SubmitBlock()` refuse toute soumission si le nœud n'est pas démarré.
3. Premier bloc: validation genesis (`previous_block_hash == "0"`, merkle root présent, transactions non vides).
4. Blocs suivants: validation de lien avec le bloc précédent (hash attendu, timestamp monotone, transactions non vides).
5. Si la validation réussit, le bloc est ajouté à `ChainState`.

## Build et tests

- `CMakeLists.txt` définit:
  - la librairie `elit21_core`.
  - l'exécutable `ELIT21d`.
  - le test `node_validation_tests` (CTests).

## Étapes suivantes recommandées

1. Remplacer le hash placeholder par SHA-256 double.
2. Implémenter une vraie racine de Merkle à partir des transactions.
3. Ajouter la validation d'en-tête (bits/PoW) et la difficulté.
4. Étendre les tests unitaires consensus/kernel/rpc.

## Flux mempool actuel

1. `Node::SubmitTransaction()` refuse si le nœud n'est pas démarré.
2. `validation::ValidateTransaction()` vérifie txid + présence d'outputs.
3. `policy::IsStandardTx()` borne le nombre d'outputs pour rester standard.
4. `node::Mempool` rejette les doublons `txid` et stocke les transactions admises.
