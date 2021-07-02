#include <iostream>
#include <cmath>

#include "SimpleTimer.h"
#include "BenchmarkTimer.h"
#include "Random.h"

using namespace poler_utils;

double simpleTimerExample() {
    SimpleTimer timer;
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
    BenchmarkTimer timer1, timer2, timer3;
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

void randomExample() {
    std::printf("Random int between 1 and 5 is: %d\n", Random::nextInt(1, 5));
    std::printf("Random double is: %f\n", Random::nextDouble());
    std::printf("Random string is: %s\n", Random::generateString(10).c_str());
}

int main() {
    simpleTimerExample();
    benchmarkTimerExample();
    randomExample();
    return 0;
}
