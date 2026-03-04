#include "common/url.h"
#include "node/mempool_args.h"
#include "rpc/protocol.h"

#include <cassert>

int main()
{
    using namespace elit21;

    const auto decoded = common::UrlDecode("ELIT21%20Core+RPC");
    assert(decoded == "ELIT21 Core RPC");

    const auto query = common::ParseQueryString("method=getblockchaininfo&verbose=1&empty=");
    assert(query.at("method") == "getblockchaininfo");
    assert(query.at("verbose") == "1");
    assert(query.at("empty").empty());

    node::MempoolArgs args;
    assert(node::ValidateMempoolArgs(args));
    assert(node::BuildMempoolArgsSummary(args) == "max=300MB, expiry=336h, persist=1");

    args.max_mempool_mb = 0;
    assert(!node::ValidateMempoolArgs(args));

    assert(rpc::IsRpcVersionSupported("1.0"));
    assert(rpc::IsRpcVersionSupported("2.0"));
    assert(!rpc::IsRpcVersionSupported("3.0"));

    const auto reply = rpc::BuildJsonRpcReply(std::optional<std::string>{"{\"bestblock\":\"abc\"}"},
                                              std::nullopt,
                                              "42");
    assert(reply ==
           "{\"result\":{\"bestblock\":\"abc\"},\"error\":null,\"id\":42}");

    return 0;
}
