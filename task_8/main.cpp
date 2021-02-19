// task_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <gtest/gtest.h>

#include "calc_volume.h"

TEST(CalcVolumeTest, AllZerosMat)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    int mat[rows * cols] = {0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0};

    //act
    int value = calc_volume(mat, rows, cols);

    //assert
    EXPECT_EQ(0, value);
}

TEST(CalcVolumeTest, AllOnesMat)
{
    //arrange
    const size_t rows = 5;
    const size_t cols = 5;
    int mat[rows * cols] = {1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1};

    //act
    int value = calc_volume(mat, rows, cols);

    //assert
    EXPECT_EQ(0, value);
}

TEST(CalcVolumeTest, SixteenVolumeMat)
{
    //arrange
    const size_t rows = 6;
    const size_t cols = 5;
    int mat[rows * cols] = {1, 1, 1, 1, 1,
                            1, 0, 0, 0, 1,
                            1, 0, 8, 0, 1,
                            1, 0, -5, 0, 1,
                            1, 0, 0, 0, 1,
                            1, 1, 1, 1, 1};

    //act
    int value = calc_volume(mat, rows, cols);

    //assert
    EXPECT_EQ(16, value);
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
