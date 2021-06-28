#include <iostream>
#include "SimpleTimer.h"
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

    std::printf("Operation took: %ld us", timer.getTimeInMicroseconds());
    return result;
}

int main() {
    simpleTimerExample();
    return 0;
}
