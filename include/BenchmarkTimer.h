#ifndef CPP_UTILS_BENCHMARKTIMER_H
#define CPP_UTILS_BENCHMARKTIMER_H

#include <vector>
#include <mutex>

#include "TimeMeasurement.h"

namespace poler_utils {

    // Provides way of measuring execution time of part of your program.
    // Keeps track of measurements performed.
    // Use start() to begin measuring, reset to stop timer and remove previous measurements
    class BenchmarkTimer {
    public:
        bool start();
        bool pause();
        bool stop();
        void reset();
        bool resume();

        [[nodiscard]] TimeMeasurement getTimeElapsed() const;
        void newMeasurement();
        TimeMeasurement getNewMeasurement();
        [[nodiscard]] std::vector<TimeMeasurement> getAllMeasurements() const;

    private:
        std::chrono::high_resolution_clock::time_point t0_;
        std::chrono::high_resolution_clock::time_point pauseTimePoint_;
        std::vector<TimeMeasurement> measurements_;
        bool started_ = false;
        bool active_ = false;
        std::mutex mtx_;
    };
}

#endif //CPP_UTILS_BENCHMARKTIMER_H
