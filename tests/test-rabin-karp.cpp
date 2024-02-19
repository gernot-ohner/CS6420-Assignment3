// Gernot F. Ohner
// CS 6420
// Assignment #1
// Instructor: Dr. Rague
// Due: 01/21/24
// Version: 1.0
// Created: 2024-01-18.
// -----------------------------------------------------------------
// This program compares the brute force and improved algorithms for
// the four sum problem implemented in FourSum.cpp.
// -----------------------------------------------------------------

#include <random>
#include <gtest/gtest.h>
#include <__random/random_device.h>

#include "../src/RabinKarp2D.h"
#include "../src/util.h"

int get_random_int(const int min, const int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

// Function to extract a random n x n square from the matrix
matrix_t extract_random_square(const std::vector<std::vector<uint8_t> > &matrix, const int n) {
    const auto max_index = matrix.size() - n; // Maximum valid starting index
    const auto start_x = get_random_int(0, max_index); // Random starting X (column)
    const auto start_y = get_random_int(0, max_index); // Random starting Y (row)

    // Create a vector to store the n x n square
    matrix_t square(n, std::vector<uint8_t>(n));

    // Extract the square
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            square[i][j] = matrix[start_y + i][start_x + j];
        }
    }

    return square;
}

TEST(Test1, BasicAssertions) {
    const auto octal = read_lines("../resources/octal.txt");
    const auto text = extract_random_square(octal, 5);
    const auto pattern = extract_random_square(text, 2);
    auto rc = RabinKarp2D{pattern, 10};

    std::cout << "    RandomTest octal.txt --->" << std::endl;

    std::cout << "    Testing a random 2x2 pattern within a random 5x5 text" << std::endl;
    std::cout << "    --------------";
    std::cout << "    Text:" << std::endl;
    print_matrix(text);

    std::cout << "    Pattern:" << std::endl;
    print_matrix(pattern);
    const auto [row, col] = test_pattern(text, pattern);
    std::cout << std::endl;
    EXPECT_NE(col, -1);
    EXPECT_NE(row, -1);
}


TEST(Test2, BasicAssertions) {
    const auto octal = read_lines("../resources/octal.txt");
    const auto text = extract_random_square(octal, 25);
    const auto pattern = extract_random_square(text, 8);
    const auto rc = RabinKarp2D{pattern, 10};

    std::cout << "    RandomTest octal.txt --->" << std::endl;

    std::cout << "    Testing a random 8x8 pattern within a random 25x25 text" << std::endl;
    std::cout << "    --------------";
    std::cout << "    Text:" << std::endl;
    print_matrix(text);

    std::cout << "    Pattern:" << std::endl;
    print_matrix(pattern);
    const auto [row, col] = test_pattern(text, pattern);
    std::cout << std::endl;
    EXPECT_NE(col, -1);
    EXPECT_NE(row, -1);
}

TEST(Test3, BasicAssertions) {
    const auto octal = read_lines("../resources/octal.txt");
    const auto text = extract_random_square(octal, 100);
    const auto pattern = extract_random_square(text, 16);
    const auto rc = RabinKarp2D{pattern, 10};

    std::cout << "    RandomTest octal.txt --->" << std::endl;

    std::cout << "    Testing a random 16x16 pattern within a random 100x100 text" << std::endl;
    std::cout << "    --------------";

    const auto [row, col] = test_pattern(text, pattern);
    std::cout << std::endl;
    EXPECT_NE(col, -1);
    EXPECT_NE(row, -1);
}

TEST(Test4, BasicAssertions) {
    const auto octal = read_lines("../resources/octal.txt");
    const auto pattern = extract_random_square(octal, 64);
    const auto rc = RabinKarp2D{pattern, 10};

    std::cout << "    RandomTest octal.txt --->" << std::endl;

    std::cout << "    Testing a random 16x16 pattern within a random 100x100 text" << std::endl;
    std::cout << "    --------------";

    const auto [row, col] = test_pattern(octal, pattern);
    std::cout << std::endl;
    EXPECT_NE(col, -1);
    EXPECT_NE(row, -1);
}