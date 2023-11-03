#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(AwardsTests, testWorks) {
    RankList list = new RankList;
    AwardCeremonyActions actions = new AwardCeremonyActions;
    EXPECT_NO_THROW(performAwardCeremony(list, actions));
    SHOULD_BE_CALLED(actions.playAnthem, 1);
    SHOULD_BE_CALLED(actions.awardBronze, 1);
    SHOULD_BE_CALLED(actions.awardSilver, 1);
    SHOULD_BE_CALLED(actions.awardGold, 1);
    SHOULD_BE_CALLED(actions.turnOffTheLightsAndGoHome, 1);
}