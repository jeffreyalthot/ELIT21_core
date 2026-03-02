#include "consensus/params.h"
#include "node/node.h"
#include "rpc/blockchain.h"

#include <iostream>

int main()
{
    elit21::node::Node node(elit21::consensus::MainNetParams());
    if (!node.Start()) {
        std::cerr << "Impossible de démarrer le noeud ELIT21" << std::endl;
        return 1;
    }

    std::cout << "ELIT21 Core démarré: " << elit21::rpc::GetBlockchainInfo(node) << std::endl;
    return 0;
}
