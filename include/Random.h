#ifndef CPP_UTILS_RANDOM_H
#define CPP_UTILS_RANDOM_H

#include <string>
#include <vector>
#include <random>

namespace poler::utils {
    class Random {
    public:
        Random(const Random&) = delete;
        void operator=(const Random&) = delete;

        static Random& getInstance();

        // returns int greater than or equal to 0 and less than INT32_MAX
        static int nextInt();
        // returns int greater than or equal to 0 and less than max
        // or the other way round, if max < 0
        static int nextInt(int max);
        // returns int greater than or equal to min and less than max
        // or the other way round, if max < min
        static int nextInt(int min, int max);

        // returns float between 0 and 1 (inclusive)
        static float nextFloat();
        // returns float between 0 and max (inclusive)
        static float nextFloat(float max);
        // returns float between min and max (inclusive)
        static float nextFloat(float min, float max);

        // returns double between 0 and 1 (inclusive)
        static double nextDouble();
        // returns double between 0 and max (inclusive)
        static double nextDouble(double max);
        // returns double between min and max (inclusive)
        static double nextDouble(double min, double max);

        static std::string generateString(size_t length);
        static std::string generateLettersOnlyString(size_t length);

        static std::vector<int> generateIntVector(size_t length);
        static std::vector<int> generateIntVector(size_t length, int max);
        static std::vector<int> generateIntVector(size_t length, int min, int max);
        static std::vector<int> generatePermutation(int min, int max);

        static std::vector<double> generateDoubleVector(size_t length);
        static std::vector<double> generateDoubleVector(size_t length, double max);
        static std::vector<double> generateDoubleVector(size_t length, double min, double max);
    private:
        Random() = default;
        std::random_device rd_{};
        std::mt19937 generator_{rd_()};
    };
}

#endif //CPP_UTILS_RANDOM_H
