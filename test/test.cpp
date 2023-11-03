#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;

TEST(HailStoneTests, testZero) {
    EXPECT_FALSE(satisfiesHailstone(0));
}
TEST(HailStoneTests, testOne) {
    EXPECT_TRUE(satisfiesHailstone(1));
}
TEST(HailStoneTests, testEven) {
    EXPECT_TRUE(satisfiesHailstone(6));
}
TEST(HailStoneTests, testOdd) {
    EXPECT_TRUE(satisfiesHailstone(7));
}
