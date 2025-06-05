#include <gtest/gtest.h>
#include <vector>
#include <numeric> 
#include <cstdint>
#include "my_mean.h" 

// Empty value test
TEST(MeanFunctionTest, EmptyVector) {
    std::vector<uint8_t> data;
    EXPECT_EQ(myMean(data), 0);
}

TEST(MeanFunctionTest, OnlyZeroVector) {
    std::vector<uint8_t> data;
    EXPECT_EQ(myMean(data), 0);
}

// Rounding logic test
TEST(MeanFunctionTest, RoundingLogic) {
    // Positive value
    EXPECT_EQ(myMean(std::vector<uint8_t>{1, 2}), 2) << "Avg 1.5 -> 2 (uint8)";
    EXPECT_EQ(myMean(std::vector<uint8_t>{1, 1, 2}), 1) << "Avg 1.33 -> 1 (uint8)";
    EXPECT_EQ(myMean(std::vector<uint8_t>{1, 1, 1, 1, 4}), 2) << "Avg 1.6 -> 2 (uint8)";

    // Negative value
    EXPECT_EQ(myMean(std::vector<int8_t>{-2, -1}), -2) << "Avg -1.5 -> -2 (int8)"; 
    EXPECT_EQ(myMean(std::vector<int8_t>{-1, -1, -2}), -1) << "Avg -1.33 -> -1 (int8)";
    EXPECT_EQ(myMean(std::vector<int8_t>{-1, -1, -1, -1, -4}), -2) << "Avg -1.6 -> -2 (int8)";

    // round to zero
    EXPECT_EQ(myMean(std::vector<int8_t>{1, -1, 1}), 0) << "Avg 0.33 -> 0 (int8)";
    EXPECT_EQ(myMean(std::vector<int8_t>{-1, 1, -1}), 0) << "Avg -0.33 -> 0 (int8)";
    EXPECT_EQ(myMean(std::vector<int8_t>{1, 0}), 1) << "Avg 0.5 -> 1 (int8)"; 
    EXPECT_EQ(myMean(std::vector<int8_t>{0, -1}), -1) << "Avg -0.5 -> -1 (int8)";
}

// Boundary test and edge case
TEST(MeanFunctionTest, BoundaryAndOverflow) {
    
    // Full range uint8_t
    std::vector<uint8_t> data_uint8(256);
    std::iota(data_uint8.begin(), data_uint8.end(), 0);
    EXPECT_EQ(myMean(data_uint8), 128);

    // Full range int8_t
    std::vector<int8_t> data_int8(256);
    std::iota(data_int8.begin(), data_int8.end(), -128);
    EXPECT_EQ(myMean(data_int8), -1);

    // All max value for uint8_t
    EXPECT_EQ(myMean(std::vector<uint8_t>(10000, 255)), 255);

    // All min value for int8_t
    EXPECT_EQ(myMean(std::vector<int8_t>(10000, -128)), -128);
}


