#include "util/time.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace elit21::util {

std::int64_t GetTimeSeconds()
{
    const auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
}

std::string FormatISO8601(const std::int64_t timestamp)
{
    const std::time_t t = static_cast<std::time_t>(timestamp);

    std::tm utc_tm{};
#if defined(_WIN32)
    gmtime_s(&utc_tm, &t);
#else
    gmtime_r(&t, &utc_tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&utc_tm, "%Y-%m-%dT%H:%M:%SZ");
    return oss.str();
}

} // namespace elit21::util
