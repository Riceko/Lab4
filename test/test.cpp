#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;

// 4 passing tests
TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testIsosceles) {
    Triangle *aTriangle = new Triangle(5,3,3);
    bool isoceles = aTriangle->isIsosceles();
    EXPECT_TRUE (isoceles);
}

TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(5,4,3);
    EXPECT_EQ (aTriangle->getArea(),6);
}

TEST(TriangleTests, testEquilateral) {
    Triangle *aTriangle = new Triangle(4,4,4);
    bool equilateral = aTriangle->isEquilateral();
    EXPECT_TRUE (equilateral);
}

// 1 using EXPECT_DEATH
TEST(TriangleTests, testCreation) {
    Triangle *aTriangle;
    EXPECT_DEATH (aTriangle = new Triangle(5,3,3), "Does not satisfy triangle inequality");
}

// 3 failing tests
TEST(TriangleTests, testPerimeter2) {
    Triangle *aTriangle = new Triangle(3,3,2);
    EXPECT_EQ (aTriangle->getPerimeter(),8);
}

TEST(TriangleTests, testArea2) {
    Triangle *aTriangle = new Triangle(4,4,2);
    ASSERT_DOUBLE_EQ (3.87, aTriangle->getArea());
}

TEST(TriangleTests, testKind) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getKind(),EQUILATERAL);
}