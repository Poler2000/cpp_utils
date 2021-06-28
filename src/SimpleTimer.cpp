#include "SimpleTimer.h"

poler_utils::SimpleTimer::SimpleTimer() {
    t0 = std::chrono::high_resolution_clock::now();
}

long poler_utils::SimpleTimer::getTimeInSeconds() const {
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(t1 - t0).count();
}

long poler_utils::SimpleTimer::getTimeInMilliseconds() const {
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
}

long poler_utils::SimpleTimer::getTimeInMicroseconds() const {
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
}

long poler_utils::SimpleTimer::getTimeInNanoseconds() const {
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
}
