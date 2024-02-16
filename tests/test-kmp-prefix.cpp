//
// Created by Gernot Ohner on 2024-02-16.
//

#include <gtest/gtest.h>

#include "../src/KMPPrefixFunction.h"

TEST(Test1, BasicAssertions) {
    const std::string input = "ababaca";
    const auto result = KMPPrefixFunction::compute_prefix_function(input, input.length());
    const std::vector<int> expected{0, 0, 1, 2, 3, 0, 1};
    EXPECT_EQ(result, expected);
    std::cout << "ComputePrefix " << input << " ---> ";
    for (const int& digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
}


TEST(Test2, BasicAssertions) {
    const std::string input = "01111000110101011010";
    const auto result = KMPPrefixFunction::compute_prefix_function(input, input.length());
    const std::vector<int> expected{0,0,0,0,0,1,1,1,2,3,1,2,1,2,1,2,3,1,2,1};
    EXPECT_EQ(result, expected);
    std::cout << "ComputePrefix " << input << " ---> ";
    for (const int& digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
}


TEST(Test3, BasicAssertions) {
    const std::string input = "aaaaaaaabbbbbbbb";
    const auto result = KMPPrefixFunction::compute_prefix_function(input, input.length());
    const std::vector<int> expected{0,1,2,3,4,5,6,7,0,0,0,0,0,0,0,0};
    EXPECT_EQ(result, expected);
    std::cout << "ComputePrefix " << input << " ---> ";
    for (const int& digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
}


TEST(Test4, BasicAssertions) {
    const std::string input = "abab";
    const auto result = KMPPrefixFunction::compute_prefix_function(input, input.length());
    const std::vector<int> expected{0, 0, 1, 2};
    EXPECT_EQ(result, expected);
    std::cout << "ComputePrefix " << input << " ---> ";
    for (const int& digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
}

