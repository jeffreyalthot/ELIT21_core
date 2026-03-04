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

- `src/clientversion.{h,cpp}` : identité/version du client ELIT21 (équivalent de rôle `clientversion.*`).
- `src/util/system.{h,cpp}` et `src/util/strencodings.{h,cpp}` : base utilitaire système/encodage.
- `src/interfaces/node.{h,cpp}` : interface de nœud orientée intégration.
- `src/index/base.{h,cpp}` et `src/index/blockfilterindex.{h,cpp}` : fondation d’index de chaîne.
- `src/policy/fees.{h,cpp}` et `src/policy/rbf.{h,cpp}` : primitives de policy (relay fee + opt-in RBF).
- `src/node/connection_types.h`, `src/node/eviction.{h,cpp}`, `src/node/txreconciliation.{h,cpp}`, `src/node/warnings.{h,cpp}` : composants node/p2p de structure Bitcoin-like.
- `src/rpc/net.{h,cpp}` et `src/rpc/rawtransaction.{h,cpp}` : endpoints RPC réseau/transaction brute.
- `src/wallet/wallet.{h,cpp}` : squelette wallet ELIT21.

## Objectif

Recréer une base de fichiers proche de Bitcoin Core tout en gardant une implémentation ELIT21-specific et progressive.

- `src/net_permissions.{h,cpp}` : permissions réseau (`noban`, `relay`, `forcerelay`) inspirées de `net_permissions.*`.
- `src/node/addrdb.{h,cpp}` : abstraction de base de chemin pour la base de pairs (`peers.dat`) dans l'esprit `node/addrdb.*`.
- `src/node/blockstorage.{h,cpp}` : métadonnées de stockage bloc (fichiers/tailles) pour aligner la structure avec les responsabilités de block storage.
- `src/rpc/util.{h,cpp}` : utilitaires RPC transverses (normalisation de méthode).
- `src/common/settings.{h,cpp}` : gestion des paramètres runtime en mémoire.
- `src/kernel/context.{h,cpp}` : objet de contexte kernel pour brancher le chainstate actif.
- `src/node/txorphanage.{h,cpp}` : stockage des transactions orphelines dans la pile P2P.
- `src/rpc/request.{h,cpp}` : modèle de requête RPC + validation de méthode.
- `src/common/messages.{h,cpp}` : catalogue minimal de messages internes pour aligner la couche `common/` avec l’esprit Bitcoin Core.
- `src/node/interface_ui.{h,cpp}` : base d’interface UI (`info/warning/error`) inspirée du rôle de `node/interface_ui.*`.
- `src/logging.{h,cpp}` : journalisation catégorisée côté runtime (net/rpc/validation/mempool/node).
- `src/util/time.{h,cpp}` : utilitaires de temps UTC (`GetTimeSeconds`, `FormatISO8601`) similaires à la couche utilitaire de Bitcoin Core.
- `src/common/url.{h,cpp}`, `src/node/mempool_args.{h,cpp}`, `src/rpc/protocol.{h,cpp}` : socle additionnel pour parser les requêtes URL, valider les options mempool et formaliser les réponses JSON-RPC dans un style Bitcoin-like.

