#include "gtest/gtest.h"
#include "../include/Awards.h"
#include <gmock/gmock.h>
#include <vector>
#include <iostream>
using namespace std;
using namespace awards;
using awards::RankList;
using awards::AwardCeremonyActions;
using ::testing::InSequence;


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



