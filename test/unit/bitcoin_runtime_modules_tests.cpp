#include "logging.h"
#include "util/time.h"

#include <cassert>

int main()
{
    elit21::Logger logger;
    logger.Enable(elit21::LogCategory::kNet);

    logger.Log(elit21::LogCategory::kRpc, "ignored");
    assert(logger.Entries().empty());

    logger.Log(elit21::LogCategory::kNet, "peer connected");
    assert(logger.Entries().size() == 1);

    const auto last = logger.Last();
    assert(last.has_value());
    assert(last->find("[net]") == 0);

    const auto timestamp = elit21::util::GetTimeSeconds();
    const auto formatted = elit21::util::FormatISO8601(timestamp);
    assert(formatted.size() == 20);
    assert(formatted[4] == '-');
    assert(formatted[10] == 'T');
    assert(formatted.back() == 'Z');

    return 0;
}
