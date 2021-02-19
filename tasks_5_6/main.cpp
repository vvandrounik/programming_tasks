// tasks_5_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gtest/gtest.h>
#include "check_island.h"

TEST(IslandsCountTest, AllZerosMatFourDir)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    uint8_t mat[rows * cols] = {0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0};

    //act
    uint16_t value = count_islands(mat, rows, cols, false);

    //assert
    EXPECT_EQ(0, value);
}

TEST(IslandsCountTest, AllOnesMatFourDir)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    uint8_t mat[rows * cols] = {1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1};

    //act
    uint16_t value = count_islands(mat, rows, cols, false);

    //assert
    EXPECT_EQ(1, value);
}

TEST(IslandsCountTest, SixIslandsMatFourDir)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    uint8_t mat[rows * cols] = {1, 1, 0, 0, 0,
                                0, 1, 0, 0, 1,
                                1, 0, 0, 1, 1,
                                0, 0, 0, 0, 0,
                                1, 0, 1, 0, 1};

    //act
    uint16_t value = count_islands(mat, rows, cols, false);

    //assert
    EXPECT_EQ(6, value);
}

TEST(IslandsCountTest, AllZerosMatSixDir)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    uint8_t mat[rows * cols] = { 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0 };

    //act
    uint16_t value = count_islands(mat, rows, cols, true);

    //assert
    EXPECT_EQ(0, value);
}

TEST(IslandsCountTest, AllOnesMatSixDir)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    uint8_t mat[rows * cols] = { 1, 1, 1, 1, 1,
                                 1, 1, 1, 1, 1,
                                 1, 1, 1, 1, 1,
                                 1, 1, 1, 1, 1,
                                 1, 1, 1, 1, 1 };

    //act
    uint16_t value = count_islands(mat, rows, cols, true);

    //assert
    EXPECT_EQ(1, value);
}

TEST(IslandsCountTest, FiveIslandsSixDir)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    uint8_t mat[rows * cols] = {1, 1, 0, 0, 0,
                                0, 1, 0, 0, 1,
                                1, 0, 0, 1, 1,
                                0, 0, 0, 0, 0,
                                1, 0, 1, 0, 1};

    //act
    uint16_t value = count_islands(mat, rows, cols, true);

    //assert
    EXPECT_EQ(5, value);
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
