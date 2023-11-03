#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(AwardsTests, testWorks) {
    RankList list = new RankList;
    AwardCeremonyActions actions = new AwardCeremonyActions;
    EXPECT_NO_THROW(performAwardCeremony(list, actions));
    
}