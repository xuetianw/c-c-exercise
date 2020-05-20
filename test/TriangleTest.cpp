

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Triangle.h"
#include <iostream>

using shapes::Triangle;

struct TriangleTests : testing:: Test {
    std :: unique_ptr<Triangle> triangle = std :: make_unique<Triangle>(5,4,3);
    std :: unique_ptr<Triangle> triangle2 = std :: make_unique<Triangle>(4,4,4);
};

TEST_F(TriangleTests, Perimeter_fail){
    EXPECT_EQ(12, triangle->getPerimeter());
}

TEST_F(TriangleTests, Perimeter_pass) {
    EXPECT_EQ(12, triangle2->getPerimeter());
}

TEST_F(TriangleTests, Kind_fail) {
    EXPECT_EQ(Triangle::Kind::EQUILATERAL, triangle2->getKind());
}

TEST_F(TriangleTests, Kind_pass) {
    EXPECT_EQ(Triangle::Kind::SCALENE, triangle->getKind());
}

TEST_F(TriangleTests, Area_fail) {
    EXPECT_EQ(6, triangle->getArea());
}

TEST_F(TriangleTests, Area_pass) {
    EXPECT_EQ(sqrt(48), triangle2->getArea());
}

//TEST_F(TriangleTests, Perimeter_pass) {
//    EXPECT_EQ(Triangle::Kind::EQUILATERAL, triangle->getKind());
//}
//
