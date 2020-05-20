
//
// Created by fred on 21/01/19.
//

#include <gtest/gtest.h>
//#include <MockTurtle.h>
#include "Hailstone.h"

using sequence::satisfiesHailstone;



TEST(HailstoneTests, number_zero_test) {
    EXPECT_EQ(false, satisfiesHailstone(0));
}

TEST(HailstoneTests, number_one_test) {
    EXPECT_EQ(true, satisfiesHailstone(1));
}

TEST(HailstoneTests, even_number_test) {
    EXPECT_EQ(false, satisfiesHailstone(8));
}
TEST(HailstoneTests, odd_number_test) {
    EXPECT_EQ(true, satisfiesHailstone(7));
}

//TEST(PainterTest, CanDrawSomething) {
//    MockTurtle turtle;                          // #2
//    EXPECT_CALL(turtle, PenDown())              // #3
//            .Times(AtLeast(1));
//
//    Painter painter(&turtle);                   // #4
//
//    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
//}                                             // #5
