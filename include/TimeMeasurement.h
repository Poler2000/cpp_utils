#ifndef CPP_UTILS_TIMEMEASUREMENT_H
#define CPP_UTILS_TIMEMEASUREMENT_H

#include <chrono>

namespace poler::utils {
    struct TimeMeasurement {
        explicit TimeMeasurement(std::chrono::high_resolution_clock::duration duration) :
            minutes(std::chrono::duration_cast<std::chrono::minutes>(duration).count()),
            seconds(std::chrono::duration_cast<std::chrono::seconds>(duration).count()),
            milliseconds(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()),
            microseconds(std::chrono::duration_cast<std::chrono::microseconds>(duration).count()),
            nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()) {}

        long minutes;
        long seconds;
        long milliseconds;
        long microseconds;
        long nanoseconds;
    };
}


#endif //CPP_UTILS_TIMEMEASUREMENT_H
