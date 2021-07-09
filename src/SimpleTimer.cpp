#include "SimpleTimer.h"

namespace poler::utils {
    SimpleTimer::SimpleTimer() {
        t0_ = std::chrono::high_resolution_clock::now();
    }

    long SimpleTimer::getTimeInSeconds() const {
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(t1 - t0_).count();
    }

    long SimpleTimer::getTimeInMilliseconds() const {
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0_).count();
    }

    long SimpleTimer::getTimeInMicroseconds() const {
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0_).count();
    }

    long SimpleTimer::getTimeInNanoseconds() const {
        auto t1 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0_).count();
    }
}

