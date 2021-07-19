#include <algorithm>
#include "Random.h"

namespace poler::utils {
    Random& Random::getInstance() {
        static Random instance;
        return instance;
    }

    int Random::nextInt() {
        return nextInt(0, INT32_MAX);
    }

    int Random::nextInt(const int max) {
        return nextInt(0, max);
    }

    int Random::nextInt(const int min, const int max) {
        if (min > max) {
            std::uniform_int_distribution<int> dis(max, min - 1);
            return dis(getInstance().generator_);
        }

        std::uniform_int_distribution<int> dis(min, max - 1);

        return dis(getInstance().generator_);
    }

    float Random::nextFloat() {
        return nextFloat(0.0f, 1.0f);
    }

    float Random::nextFloat(const float max) {
        return nextFloat(0.0f, max);
    }

    float Random::nextFloat(const float min, const float max) {
        std::uniform_real_distribution<float> dis(min, max);

        return dis(getInstance().generator_);
    }

    double Random::nextDouble() {
        return nextDouble(0.0, 1.0);
    }

    double Random::nextDouble(const double max) {
        return nextDouble(0.0, max);
    }

    double Random::nextDouble(const double min, const double max) {
        std::uniform_real_distribution<double> dis(min, max);

        return dis(getInstance().generator_);
    }

    std::string Random::generateString(const size_t length) {
        static constexpr size_t minCharacterCode = 33;
        static constexpr size_t maxCharacterCode = 126;

        std::string s;

        for (size_t i = 0; i < length; i++) {
            s += char(nextInt(minCharacterCode, maxCharacterCode));
        }
        return s;
    }

    std::string Random::generateLettersOnlyString(const size_t length) {
        static constexpr size_t minCharacterCode = 'a';
        static constexpr size_t maxCharacterCode = 'z';

        std::string s;

        for (size_t i = 0; i < length; i++) {
            s += char(nextInt(minCharacterCode, maxCharacterCode));
        }
        return s;
    }

    std::vector<int> Random::generateIntVector(const size_t length) {
        std::vector<int> vec(length);

        for (size_t i = 0; i < length; i++) {
            vec[i] = nextInt();
        }
        return vec;
    }

    std::vector<int> Random::generateIntVector(const size_t length, const int max) {
        return generateIntVector(length, 0, max);
    }

    std::vector<int> Random::generateIntVector(const size_t length, const int min, const int max) {
        std::vector<int> vec(length);

        for (size_t i = 0; i < length; i++) {
            vec[i] = nextInt(min, max);
        }
        return vec;
    }

    std::vector<int> Random::generatePermutation(const int min, const int max) {
        std::vector<int> vec(max - min + 1);

        for (size_t i = 0; i <= size_t(max - min); i++) {
            vec[i] = min + i;
        }
        std::shuffle(vec.begin(), vec.end(), getInstance().generator_);

        return vec;
    }

    std::vector<double> Random::generateDoubleVector(const size_t length) {
        std::vector<double> vec(length);

        for (size_t i = 0; i < length; i++) {
            vec[i] = nextDouble();
        }
        return vec;
    }

    std::vector<double> Random::generateDoubleVector(const size_t length, const double max) {
        return generateDoubleVector(length, 0, max);
    }

    std::vector<double> Random::generateDoubleVector(const size_t length, const double min, const double max) {
        std::vector<double> vec(length);

        for (size_t i = 0; i < length; i++) {
            vec[i] = nextDouble(min, max);
        }
        return vec;
    }
}

