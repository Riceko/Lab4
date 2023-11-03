
#ifndef AWARDS_H
#define AWARDS_H

#include <string>


namespace mock_awards {


class StubRankList: public RankList {
public:
  int counter = 1;
  std::string getNext() {
    if (counter == 1) {
      counter++;
      return "Caleb";
    } else if (counter == 2) {
      counter++;
      return "Nathan";
    } else if (counter == 3) {
      counter++;
      return "Will";
    }
  }
};


class MockAwardCeremonyActions {
public:
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
    MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
    MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
    MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
};


void performAwardCeremony(RankList& recipients, AwardCeremonyActions& actions);


}


#endif
