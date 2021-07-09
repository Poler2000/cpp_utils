#include "BenchmarkTimer.h"

namespace poler::utils {
    bool BenchmarkTimer::start() {
        mtx_.lock();
        if (started_) {
            mtx_.unlock();
            return false;
        }
        started_ = true;
        active_ = true;
        t0_ = std::chrono::high_resolution_clock::now();
        mtx_.unlock();

        return true;
    }

    bool BenchmarkTimer::pause() {
        mtx_.lock();
        if (!active_) {
            mtx_.unlock();
            return false;
        }
        active_ = false;
        pauseTimePoint_ = std::chrono::high_resolution_clock::now();
        mtx_.unlock();

        return true;
    }

    bool BenchmarkTimer::stop() {
        mtx_.lock();
        if (!started_) {
            mtx_.unlock();
            return false;
        }
        started_ = false;
        active_ = false;
        mtx_.unlock();

        return true;
    }

    void BenchmarkTimer::reset() {
        mtx_.lock();
        started_ = false;
        active_ = false;
        measurements_.clear();
        mtx_.unlock();
    }

    bool BenchmarkTimer::resume() {
        mtx_.lock();
        if (active_) {
            mtx_.unlock();
            return false;
        }
        active_ = true;
        auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
        t0_ = std::chrono::high_resolution_clock::time_point(now - pauseTimePoint_.time_since_epoch() + t0_.time_since_epoch());
        mtx_.unlock();

        return true;
    }

    TimeMeasurement BenchmarkTimer::getTimeElapsed() const {
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = (t0_.time_since_epoch().count() == 0) ?
                       t0_.time_since_epoch() :
                       std::chrono::high_resolution_clock::duration(now - t0_);

        return TimeMeasurement{elapsed};
    }

    void BenchmarkTimer::newMeasurement() {
        auto timePoint = getTimeElapsed();
        measurements_.emplace_back(timePoint);
    }

    TimeMeasurement BenchmarkTimer::getNewMeasurement() {
        auto timePoint = getTimeElapsed();
        measurements_.emplace_back(timePoint);

        return timePoint;
    }

    std::vector<TimeMeasurement> BenchmarkTimer::getAllMeasurements() const {
        return measurements_;
    }
}