#include "common/args.h"

#include <cstdlib>
#include <fstream>
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

} // namespace

int main()
{
    bool ok = true;

    elit21::common::ArgsManager args;
    const char* argv[] = {"ELIT21d", "-datadir=/tmp/cli-data", "-listen=0", "-server"};
    ok &= Expect(args.ParseParameters(4, argv), "parse cli args");
    ok &= Expect(args.IsArgSet("server"), "recognizes boolean-style arg");
    ok &= Expect(args.GetArg("datadir", "") == "/tmp/cli-data", "reads datadir from cli");

    const std::string conf_path = "args_test.conf";
    {
        std::ofstream conf(conf_path);
        conf << "# comment\n";
        conf << "datadir=./from-conf\n";
        conf << "rpcport=21322\n";
    }

    ok &= Expect(args.ReadConfigFile(conf_path), "loads config file");
    ok &= Expect(args.GetArg("rpcport", "") == "21322", "reads config key");
    ok &= Expect(args.GetArg("datadir", "") == "/tmp/cli-data", "cli overrides config");

    std::remove(conf_path.c_str());

    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
