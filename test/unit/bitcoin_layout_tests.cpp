#include "addrman.h"
#include "banman.h"
#include "txdb.h"
#include "txmempool.h"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

bool Expect(const bool condition, const std::string& message)
{
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
        return false;
    }
    return true;
}

elit21::Transaction MakeTx(const std::string& txid)
{
    return elit21::Transaction{txid, {"in"}, {"out"}};
}

} // namespace

int main()
{
    bool ok = true;

    elit21::AddrMan addrman;
    ok &= Expect(addrman.Add("elit21.com:21321"), "add endpoint");
    ok &= Expect(!addrman.Add("elit21.com:21321"), "reject duplicate endpoint");
    ok &= Expect(addrman.IsKnown("elit21.com:21321"), "endpoint is known");
    ok &= Expect(addrman.MarkGood("elit21.com:21321"), "mark endpoint good");

    elit21::BanMan banman;
    ok &= Expect(banman.Ban("192.168.1.10"), "ban address");
    ok &= Expect(!banman.Ban("192.168.1.10"), "reject duplicate ban");
    ok &= Expect(banman.IsBanned("192.168.1.10"), "address is banned");
    ok &= Expect(banman.Unban("192.168.1.10"), "unban address");

    elit21::TxMemPool mempool;
    std::string error;
    ok &= Expect(mempool.Add(MakeTx("txA"), error), "tx added to txmempool alias");

    elit21::TxDB txdb;
    ok &= Expect(txdb.WriteBestBlockHash("000000abc"), "store best block hash");
    ok &= Expect(txdb.ReadBestBlockHash().value_or("") == "000000abc", "read best block hash");
    ok &= Expect(txdb.WriteTxHeight("txA", 42), "store tx height");
    ok &= Expect(txdb.ReadTxHeight("txA").value_or(-1) == 42, "read tx height");

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
