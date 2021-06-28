#ifndef CPP_UTILS_SIMPLETIMER_H
#define CPP_UTILS_SIMPLETIMER_H

#include <chrono>

namespace poler_utils {
    class SimpleTimer {
    public:
        SimpleTimer();
        [[nodiscard]] long getTimeInSeconds() const;
        [[nodiscard]] long getTimeInMilliseconds() const;
        [[nodiscard]] long getTimeInMicroseconds() const;
        [[nodiscard]] long getTimeInNanoseconds() const;
    private:
        std::chrono::high_resolution_clock::time_point t0;
    };
}

#endif //CPP_UTILS_SIMPLETIMER_H
