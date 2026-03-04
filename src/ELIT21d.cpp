#include "common/args.h"
#include "consensus/params.h"
#include "init.h"
#include "node/node.h"
#include "rpc/blockchain.h"
#include "rpc/mempool.h"

#include <iostream>

int main(int argc, const char* argv[])
{
    elit21::common::ArgsManager args;
    args.ParseParameters(argc, argv);

    const std::string config_path = args.GetArg("conf", "config/ELIT21.conf");
    args.ReadConfigFile(config_path);

    elit21::node::Node node(elit21::consensus::MainNetParams());
    elit21::node::NodeContext node_context = node.BuildContext();
    if (!elit21::AppInitMain(node_context)) {
        std::cerr << "Contexte ELIT21 invalide" << std::endl;
        return 1;
    }

    if (!node.Start()) {
        std::cerr << "Impossible de demarrer le noeud ELIT21" << std::endl;
        return 1;
    }

    std::cout << "ELIT21 Core demarre: " << elit21::rpc::GetBlockchainInfo(node) << std::endl;
    std::cout << "Mempool: " << elit21::rpc::GetMempoolInfo(node) << std::endl;
    std::cout << "datadir=" << args.GetArg("datadir", "./datadir") << std::endl;
    std::cout << "config=" << config_path << std::endl;
    return 0;
}
