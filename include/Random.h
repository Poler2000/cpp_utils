#ifndef CPP_UTILS_RANDOM_H
#define CPP_UTILS_RANDOM_H

#include <string>
#include <vector>
#include <random>

namespace poler_utils {
    class Random {
    public:
        Random(const Random&) = delete;
        void operator=(const Random&) = delete;

        static Random& getInstance();

        static int nextInt();
        static int nextInt(int max);
        static int nextInt(int min, int max);

        static float nextFloat();
        static float nextFloat(float max);
        static float nextFloat(float min, float max);

        static double nextDouble();
        static double nextDouble(double max);
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
