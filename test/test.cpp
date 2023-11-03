#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;

TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

// 4 passing tests
TEST(TriangleTests, testIsosceles) {
    Triangle *aTriangle = new Triangle(5,3,3);
    bool isoceles = aTriangle->isIsosceles();
    EXPECT_TRUE (isoceles);
}

TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(5,4,4);
    // ASSERT_DOUBLE_EQ (7.806, aTriangle->getArea());
    // ASSERT_NEAR(val1, val2, abs_error);
    ASSERT_NEAR(aTriangle->getArea(), 7.806, 0.001);
}

TEST(TriangleTests, testEquilateral) {
    Triangle *aTriangle = new Triangle(4,4,4);
    bool equilateral = aTriangle->isEquilateral();
    EXPECT_TRUE (equilateral);
}

TEST(TriangleTests, testPerimeter2) {
    Triangle *aTriangle = new Triangle(10,10,10);
    EXPECT_EQ (aTriangle->getPerimeter(),30);
}

// 1 using EXPECT_DEATH
TEST(TriangleTests, testCreation) {
    Triangle *aTriangle;
    EXPECT_DEATH (aTriangle = new Triangle(5,3,1), "Does not satisfy triangle inequality");
}

// 3 failing tests
TEST(TriangleTests, testPerimeter3) {
    Triangle *aTriangle = new Triangle(3,3,2);
    EXPECT_EQ (aTriangle->getPerimeter(),8);
}

TEST(TriangleTests, testArea2) {
    Triangle *aTriangle = new Triangle(4,4,2);
    ASSERT_NEAR(aTriangle->getArea(), 3.87, 0.01);
}

TEST(TriangleTests, testKind) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getKind(),Triangle::Kind::EQUILATERAL);
}