# Arborescence ELIT21 Core (inspirée de Bitcoin Core)

Cette étape recrée et étend une arborescence de base similaire à Bitcoin Core pour poser les fondations du projet.

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
- `src/node/chainman.{h,cpp}` : gestionnaire de chaîne active (inspiration `ChainstateManager`).
- `src/rpc/blockchain.{h,cpp}` : endpoint d'information blockchain.
- `doc/ARCHITECTURE.md` : documentation de l'architecture bootstrap.

## Fichiers de structure supplémentaires (inspiration Bitcoin Core)

- `src/chain.{h,cpp}` : primitives de chaîne actives (`BlockIndex`, `Chain`) pour préparer une structure proche de Bitcoin Core.
- `src/chainparams.{h,cpp}` et `src/chainparamsbase.{h,cpp}` : sélection/configuration réseau.
- `src/consensus/merkle.{h,cpp}` : calcul de racine Merkle.
- `src/pow.{h,cpp}` : vérification PoW simplifiée.
- `src/net.{h,cpp}` : registre des commandes P2P (version, ping, inv, block, tx...).
- `src/net_processing.{h,cpp}` : traitement réseau d’un nouveau bloc.
- `src/protocol.{h,cpp}` : header wire protocol (magic, commande, taille payload, checksum) pour rapprocher la structure de Bitcoin Core.
- `src/addrman.{h,cpp}` et `src/banman.{h,cpp}` : gestion minimale d'adresses/banlist proche des responsabilités réseau Bitcoin Core.
- `src/txdb.{h,cpp}` et `src/txmempool.{h,cpp}` : base de persistance transactionnelle et alias mempool avec naming Bitcoin Core.
- `src/rpc/mining.{h,cpp}` : endpoint RPC mining.
- `src/validation/validation.{h,cpp}` : validation contextuelle de bloc.
- `src/init.{h,cpp}`, `src/validationinterface.{h,cpp}` et `src/node/context.{h,cpp}` : base d'initialisation et de signaux validation inspirée Bitcoin Core.
- `src/node/blockmanager.{h,cpp}` et `src/node/peerman.{h,cpp}` : gestionnaires réseau/blocs inspirés des rôles `BlockManager` et `PeerManager` de Bitcoin Core.
- `src/common/args.{h,cpp}` + `config/ELIT21.conf` : parsing CLI/config (`bitcoin.conf`-like) pour préparer le runtime ELIT21.

## Tests supplémentaires

- `test/unit/chainparams_tests.cpp`
- `test/unit/merkle_pow_tests.cpp`
- `test/unit/chainman_tests.cpp`
- `test/unit/chain_tests.cpp`

- `test/unit/args_tests.cpp`
- `test/unit/network_stack_tests.cpp`
- `test/unit/protocol_tests.cpp`
- `test/unit/bitcoin_layout_tests.cpp`
