// task_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gtest/gtest.h>

#include "reverse_bits.h"

TEST(ReverseBitsTest, ValueOne)
{
    //arrange
    int number = 1;

    //act
    int value = reverse_bits(INT_MIN);

    //assert
    int expected = 0;
    expected |= 1 << (sizeof(int) * CHAR_BIT - 1);
    EXPECT_EQ(expected, value);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
