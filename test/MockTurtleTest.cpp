//
// Created by fred on 21/01/19.
//

#include "Turtle.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockTurtle : public Turtle {
public:
    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};


using ::testing::AtLeast;                     // #1

TEST(PainterTest, CanDrawSomething) {
    MockTurtle turtle;                          // #2
    EXPECT_CALL(turtle, PenDown())              // #3
            .Times(AtLeast(1));

    Painter painter(&turtle);                   // #4

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}                                             // #5

int main(int argc, char** argv) {
    // The following line must be executed to initialize Google Mock
    // (and Google Test) before running the tests.
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}