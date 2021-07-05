#include <gtest/gtest.h>

#include "Random.h"

static constexpr int testIterations = 1;

TEST(RandomTest, NextIntTest) {
    for (int i = 0; i < testIterations; i++) {
        int result1 = poler_utils::Random::nextInt();
        EXPECT_GE(result1, 0);

        int result2 = poler_utils::Random::nextInt(5);
        EXPECT_GE(result2, 0);
        EXPECT_LE(result2, 5);

        int result3 = poler_utils::Random::nextInt(5, 10);
        EXPECT_GE(result3, 5);
        EXPECT_LE(result3, 10);

        int result4 = poler_utils::Random::nextInt(-5, -15);
        EXPECT_GE(result4, -15);
        EXPECT_LE(result4, -5);
    }
}

TEST(RandomTest, NextFloatTest) {
    for (int i = 0; i < testIterations; i++) {
        float result1 = poler_utils::Random::nextFloat();
        EXPECT_GE(result1, 0.0f);
        EXPECT_LE(result1, 1.0f);

        float result2 = poler_utils::Random::nextFloat(5.0f);
        EXPECT_GE(result2, 0.0f);
        EXPECT_LE(result2, 5.0f);

        float result3 = poler_utils::Random::nextFloat(5.5f, 10.75f);
        EXPECT_GE(result3, 5.5f);
        EXPECT_LE(result3, 10.75f);

        float result4 = poler_utils::Random::nextFloat(-5.5f, -15.75f);
        EXPECT_GE(result4, -15.75f);
        EXPECT_LE(result4, -5.5f);
    }
}

TEST(RandomTest, NextDoubleTest) {
    for (int i = 0; i < testIterations; i++) {
        double result1 = poler_utils::Random::nextDouble();
        EXPECT_GE(result1, 0.0);
        EXPECT_LE(result1, 1.0);

        double result2 = poler_utils::Random::nextDouble(5.0);
        EXPECT_GE(result2, 0.0);
        EXPECT_LE(result2, 5.0);

        double result3 = poler_utils::Random::nextDouble(5.5, 10.75);
        EXPECT_GE(result3, 5.5);
        EXPECT_LE(result3, 10.75);

        double result4 = poler_utils::Random::nextDouble(-5.5, -15.75);
        EXPECT_GE(result4, -15.75);
        EXPECT_LE(result4, -5.5);
    }
}

TEST(RandomTest, RandomStringTest) {
    for (int i = 0; i < testIterations; i++) {
        auto emptyString = poler_utils::Random::generateString(0);
        EXPECT_STREQ(emptyString.c_str(), "");

        auto shortString = poler_utils::Random::generateString(10);
        EXPECT_EQ(shortString.length(), 10);

        auto longString = poler_utils::Random::generateString(1024);
        EXPECT_EQ(longString.length(), 1024);
    }
}

TEST(RandomTest, LettersOnlyStringTest) {
    for (int i = 0; i < testIterations; i++) {
        auto string = poler_utils::Random::generateLettersOnlyString(32);

        for (auto& c : string) {
            EXPECT_GE(c, 'a');
            EXPECT_LE(c, 'z');
        }
    }
}

TEST(RandomTest, IntVectorTest) {
    for (int i = 0; i < testIterations; i++) {
        auto vec = poler_utils::Random::generateIntVector(32, -5, 5);
        EXPECT_EQ(vec.size(), 32);

        for (auto& v : vec) {
            EXPECT_GE(v, -5);
            EXPECT_LE(v, 5);
        }
    }
}

TEST(RandomTest, RandomPermutationTest) {
    for (int i = 0; i < testIterations; i++) {
        auto vec = poler_utils::Random::generatePermutation(-5, 5);
        EXPECT_EQ(vec.size(), 11);

        for (int j = -5; j < 6; j++) {
            EXPECT_TRUE(std::find(vec.begin(), vec.end(), j) < vec.end());
        }
    }
}

TEST(RandomTest, DoubleVectorTest) {
    for (int i = 0; i < testIterations; i++) {
        auto vec = poler_utils::Random::generateDoubleVector(32, -5.5, 5.5);
        EXPECT_EQ(vec.size(), 32);

        for (auto& v : vec) {
            EXPECT_GE(v, -5.5);
            EXPECT_LE(v, 5.5);
        }
    }
}