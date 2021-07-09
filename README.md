# cpp_utils
## Table of contents
* [General info](#general-info)
* [Install](#install)
* [Examples](#examples)

## General info
This project contains a set of simple c++ utilities, which can be used in other projects. It was created in c++17 and can be further expanded in the future.

## Install
To install library, you can use the following commands:

```
$ git clone https://github.com/Poler2000/cpp_utils.git
$ cd cpp_utils
$ mkdir build && cd build
$ cmake .. && make -j
# make install
```

Then, in your cmake
```
find_package(CppUtils REQUIRED)
target_link_libraries($your-target CppUtils)
```

## Examples

### Random

```cpp
#include "Random.h"

using namespace poler::utils;

void randomExample() {
    std::printf("Random int between 1 and 5 is: %d\n", Random::nextInt(1, 5));
    std::printf("Random double is: %f\n", Random::nextDouble());
    std::printf("Random string is: %s\n", Random::generateString(10).c_str());
}
```
### SimpleTimer

```cpp
#include "SimpleTimer.h"

using namespace poler::utils;

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
```

### BenchmarkTimer

```cpp
#include "BenchmarkTimer.h"

using namespace poler::utils;

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
```
### Logger

```cpp
#include "Logger.h"

using namespace poler::utils;

void loggerExample() {
    std::string s{"Smith"};
    Logger::error("Hello, {2} {3}! You have {1}$ "
                  "in your bank account and {0} new messages!", 4, 7.31, "John", s);
}
```
