# ELIT21 Core

ELIT21 Core est une base de travail pour construire une implémentation blockchain inspirée de Bitcoin Core.

## Statut actuel

- Arborescence initiale du projet créée (proche de Bitcoin Core).
- Seed serveur initial configuré: `elit21.com`.
- Bootstrap de développement C++ commencé dans `src/` avec des modules consensus, kernel, node, mempool, policy, rpc et validation de blocs/transactions.
- Ajout d'un gestionnaire de chaîne actif (`node/chainman`) inspiré du rôle de `ChainstateManager` dans Bitcoin Core pour centraliser l'acceptation des blocs.
- Extension de l’architecture avec des fichiers analogues à Bitcoin Core: `chain*`, `chainparams*`, `pow*`, `net_processing*`, `validation*` global et RPC mining.
- Ajout d'une base de fichiers `init*`, `validationinterface*` et `node/context*` pour structurer l'initialisation comme Bitcoin Core.
- Ajout de modules réseau inspirés de Bitcoin Core: `net.*`, `node/blockmanager.*` et `node/peerman.*` pour préparer la couche P2P/stockage des blocs.
- Ajout d'une première couche de protocole wire `protocol.*` (header de message réseau, magic bytes, validation de commande) alignée avec la structure de `protocol.h` de Bitcoin Core.
- Extension de la compatibilité d'arborescence Bitcoin Core avec `addrman*`, `banman*`, `txdb*` et `txmempool*` (adaptés à ELIT21).
- Ajout d'une nouvelle vague de modules "bitcoin-like" pour poursuivre la parité de structure: `amount*`, `coins*`, `checkpoint*`, `versionbits*`, `deploymentstatus*`, `rpc/server*`, `rpc/register*` et `node/utxo_snapshot*`.
- Extension de la parité de layout Bitcoin Core avec de nouveaux fichiers de structure (`clientversion*`, `util/system*`, `util/strencodings*`, `interfaces/node*`, `index/base*`, `index/blockfilterindex*`, `policy/fees*`, `policy/rbf*`, `node/eviction*`, `node/txreconciliation*`, `node/warnings*`, `rpc/net*`, `rpc/rawtransaction*`, `wallet/wallet*`).
- Nouvelle extension de parité source Bitcoin Core avec `net_permissions*`, `node/addrdb*`, `node/blockstorage*` et `rpc/util*` pour couvrir davantage de rôles P2P, stockage bloc et utilitaires RPC.
- Poursuite de la parité Bitcoin Core avec `common/messages*` (messages internes) et `node/interface_ui*` (pont notifications UI) adaptés au runtime ELIT21.
- Ajout des modules `logging*` et `util/time*` pour rapprocher encore la couche runtime des primitives présentes dans Bitcoin Core (catégories de logs + utilitaires temporels UTC).
- Extension de parité de fichiers Bitcoin Core avec `common/init*`, `node/database_args*`, `node/types*` et `rpc/server_util*` pour préparer l'initialisation runtime, les chemins DB nœud, les constantes/propriétés de protocole et les helpers RPC serveur.
- Nouvelle vague de parité Bitcoin Core avec `node/caches*`, `node/kernel_notifications*` et `rpc/client*` pour structurer la répartition des caches node, les notifications kernel->node et le parsing RPC côté client CLI.

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
- `src/chain.{h,cpp}`: primitives de chaîne (`BlockIndex`, `Chain`, calcul de hash de bloc) inspirées de `src/chain.*` de Bitcoin Core.
- `src/node/chainman.{h,cpp}`: gestion de la chaîne active et acceptation centralisée des blocs (genesis + chaînage).
- `src/node/blockmanager.{h,cpp}`: indexation minimale des blocs reçus (protection anti-doublon).
- `src/node/peerman.{h,cpp}` + `src/net.{h,cpp}`: base du protocole P2P (peers connectés + commandes réseau de base).
- `src/protocol.{h,cpp}`: modèle de header réseau et validation de structure de message pour le wire protocol ELIT21.
- `src/amount.{h,cpp}`, `src/coins.{h,cpp}`, `src/checkpoint.{h,cpp}`: premières briques monnaie/UTXO/checkpoints dans le style Bitcoin Core.
- `src/versionbits.{h,cpp}` et `src/deploymentstatus.{h,cpp}`: base d'activation de fonctionnalités de consensus.
- `src/rpc/server.{h,cpp}` + `src/rpc/register.{h,cpp}`: registre RPC minimal proche de l'organisation Bitcoin Core.
- `src/node/utxo_snapshot.{h,cpp}`: métadonnées de snapshot UTXO pour futurs bootstrap rapides.
- `src/validation/block_validator.cpp`: règles de validation de base utilisées par `Chainman`.
- `src/validation/validation.cpp`: validation contextuelle (merkle + PoW simplifié).
- `src/chainparams.cpp`: paramètres réseau de plus haut niveau.
- `test/unit/*.cpp`: tests bloc/mempool + nouveaux tests chainparams, merkle/pow, chain manager, compatibilité de layout et modules de parité Bitcoin-like.
- `test/unit/bitcoin_runtime_modules_tests.cpp`: couverture des nouveaux modules runtime (`logging`, `util/time`).
- `test/unit/bitcoin_additional_parity_modules_tests.cpp`: validation des nouveaux modules de parité (`common/url`, `node/mempool_args`, `rpc/protocol`).
- `test/unit/bitcoin_latest_parity_modules_tests.cpp`: validation des modules de parité supplémentaires (`node/caches`, `node/kernel_notifications`, `rpc/client`).
