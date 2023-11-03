#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


TEST(HailstoneTests, testZero) {
    EXPECT_FALSE (satisfiesHailstone(0));
}

TEST(HailstoneTests, testOne) {
    bool yes = satisfiesHailstone(1);
    EXPECT_TRUE (yes);
}

TEST(HailstoneTests, testEven) {
    bool yes = satisfiesHailstone(8);
    EXPECT_TRUE (yes);
}

TEST(HailstoneTests, testEven2) {
    bool yes = satisfiesHailstone(6);
    EXPECT_TRUE (yes);
}

TEST(HailstoneTests, testOdd) {
    bool yes = satisfiesHailstone(3);
    EXPECT_TRUE (yes);
}

TEST(HailstoneTests, testOdd2) {
    EXPECT_TRUE (sequence::satisfiesHailstone(15));
}