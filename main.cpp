#include <iostream>
#include "CPolynomial.h"
#include <gtest/gtest.h>

TEST(dotTest, test1) {
    const std::array<int, 3> polynomial1 = {2, 3, 1};
    CPolynomial one(polynomial1);
    EXPECT_EQ(one.calculation(2), 12);
}

TEST(dotTest, test2) {
    const std::array<int, 4> polynomial1 = {9, 7, -3, 4};
    CPolynomial one(polynomial1);
    EXPECT_EQ(one.calculation(3), 111);
}

TEST(dotTest, test3) {
    const std::array<int, 5> polynomial1 = {2, 3, 1, 2, 5};
    CPolynomial one(polynomial1);
    EXPECT_EQ(one.calculation(4), 1438);
}

TEST(dotTest, test4) {
    const std::array<int, 3> polynomial1 = {2, 3, 1};
    CPolynomial one(polynomial1);
    EXPECT_EQ(one.calculation(5), 42);
}


int main() {
//    std::array<int, 3> polynomial1 = {2, 3, -1};
//    CPolynomial<3> one(polynomial1);
//    std::cout << one<<std::endl;
//    std::cout << one.calculation(3);
//    std::cout << one;
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();

}


