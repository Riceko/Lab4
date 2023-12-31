#include "gtest/gtest.h"
#include "../include/Triangle.h"

#include "../include/Awards.h"
#include <gmock/gmock.h>
#include <vector>
#include <iostream>
using shapes::Triangle;
using namespace std;
using namespace awards;
using awards::RankList;
using awards::AwardCeremonyActions;
using ::testing::InSequence;

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


class StubRankList : public RankList{
    private:
        int index = -1;
        vector<string> names  = {"Will","Nathan","John"} ; 
        
    public:
        string  getNext()
        {
            index++;
            return names.at(index);
        }
};
class mockAwardCeremonyActions: public awards::AwardCeremonyActions {
    public:
        MOCK_METHOD(void, playAnthem, ());
        MOCK_METHOD(void, awardBronze, (string recipient));
        MOCK_METHOD(void, awardSilver, (string recipient));
        MOCK_METHOD(void, awardGold, (string recipient));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, ());

};

TEST(AwardsTest, testCeremonyInSequence) {
    StubRankList rankList;
    mockAwardCeremonyActions ceremony;

    {
        InSequence seq;
        EXPECT_CALL(ceremony, playAnthem());
        EXPECT_CALL(ceremony, awardBronze("Will"));
        EXPECT_CALL(ceremony, awardSilver("Nathan"));
        EXPECT_CALL(ceremony, awardGold("John"));
        EXPECT_CALL(ceremony, turnOffTheLightsAndGoHome());
    }

    awards::performAwardCeremony(rankList, ceremony);
}

TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);

}
//4 pass test
TEST(TriangleTests, testIsosceles) {
    Triangle *aTriangle = new Triangle(5,3,3);
    bool isosceles = aTriangle->isIsosceles();
    EXPECT_TRUE(isosceles);
}
TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(5,4,4);
    ASSERT_NEAR (aTriangle->getArea(),7.806,.001);
}
TEST(TriangleTests, testEquilateral) {
    Triangle *aTriangle = new Triangle(4,4,4);
    bool equilateral = aTriangle->isEquilateral();
    EXPECT_TRUE(equilateral);
}
TEST(TriangleTests, testPerimeter2)
{
    Triangle *aTriangle = new Triangle(10,10,10);
    EXPECT_EQ(aTriangle->getPerimeter(), 30);
}

//1 expect_death
TEST(TriangleTests, testCreation) {
    Triangle *aTriangle;
    EXPECT_DEATH (aTriangle = new Triangle(5,3,1), "Does not satisfy triangle inequality");
}
//3 failing tests
TEST(TriangleTests, testPerimeter3)
{
    Triangle *aTriangle = new Triangle(3,3,2);
    EXPECT_EQ(aTriangle->getPerimeter(), 8);
}
TEST(TriangleTests, testArea2) {
    Triangle *aTriangle = new Triangle(4,4,2);
    ASSERT_NEAR(aTriangle->getArea(), 3.87, .01);
}
TEST(TriangleTests, testKind) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getKind(),Triangle::Kind::EQUILATERAL);

}



