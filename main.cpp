#include <iostream>
#include "SimpleTimer.h"
#include "BenchmarkTimer.h"
#include <cmath>

double simpleTimerExample() {
    poler_utils::SimpleTimer timer;
    double result = 0;

    for (int i = 0; i < 100000; i++) {
        auto number = i * sqrt(i) * M_PI;
        if (result < number) {
            result = number;
        }
    }

    std::printf("Operation took: %ld us\n", timer.getTimeInMicroseconds());
    return result;
}

double benchmarkTimerExample() {
    poler_utils::BenchmarkTimer timer1, timer2, timer3;
    double result = 0;

    timer1.start();
    timer2.start();

    for (int i = 0; i < 100000; i++) {
        timer2.pause();
        auto number = i * sqrt(i) * M_PI;
        if (result < number) {
            result = number;
        }
        timer2.resume();
    }

    std::printf("Timer 1 run for: %ld us\n", timer1.getNewMeasurement().microseconds);
    std::printf("Timer 2 run for: %ld us\n", timer2.getNewMeasurement().microseconds);
    std::printf("Timer 3 run for: %ld us\n", timer3.getNewMeasurement().microseconds);
    return result;
}

int main() {
    simpleTimerExample();
    benchmarkTimerExample();
    return 0;
}
