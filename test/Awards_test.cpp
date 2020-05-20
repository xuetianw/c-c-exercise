#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Awards.h"
#include <iostream>

using namespace awards;
using ::testing::AtLeast;
using ::testing::InSequence;

class MockAwardCeremonyActions : public AwardCeremonyActions {
public:
    MOCK_METHOD0(playAnthem, void());
    MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
    MOCK_METHOD1(awardBronze, void(std::string recipient));
    MOCK_METHOD1(awardSilver, void(std::string recipient));
    MOCK_METHOD1(awardGold, void(std::string recipient));
};

class StubRankList : public RankList {
private:
    std::vector<std::string> recipients;
public:
    std::string getNext()
    {
        std::string next = recipients.back();
        recipients.pop_back();
        return next;
    };

    void add(std::string recipient)
    {
        recipients.push_back(recipient);
    }
};

TEST(AwardsTests, PerformingAwardCeremonyTest) {
    MockAwardCeremonyActions actions;
    StubRankList rankList;
    rankList.add("100");
    rankList.add("200");
    rankList.add("300");
    {
        InSequence dummy;

        EXPECT_CALL(actions, playAnthem());
        EXPECT_CALL(actions, awardBronze("300"));
        EXPECT_CALL(actions, awardSilver("200"));
        EXPECT_CALL(actions, awardGold("100"));
        EXPECT_CALL(actions, turnOffTheLightsAndGoHome());
    }
    performAwardCeremony(rankList, actions);
}                                             // #5

int main(int argc, char** argv) {
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}