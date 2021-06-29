#ifndef CPP_UTILS_SIMPLETIMER_H
#define CPP_UTILS_SIMPLETIMER_H

#include <chrono>

namespace poler_utils {

    // Provides very basic way of measuring execution time.
    // Timer starts running when it is created and allows user to
    // get time elapsed since that time point.
    // For slightly more advanced functionality, see BenchmarkTimer class
    class SimpleTimer {
    public:
        SimpleTimer();
        [[nodiscard]] long getTimeInSeconds() const;
        [[nodiscard]] long getTimeInMilliseconds() const;
        [[nodiscard]] long getTimeInMicroseconds() const;
        [[nodiscard]] long getTimeInNanoseconds() const;
    private:
        std::chrono::high_resolution_clock::time_point t0_;
    };
}

#endif //CPP_UTILS_SIMPLETIMER_H
