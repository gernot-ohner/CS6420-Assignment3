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

#include <gtest/gtest.h>

#include "../src/RabinKarp2D.h"
#include "../src/util.h"

TEST(Test1, BasicAssertions) {

    const matrix_t pattern1 = {{1, 2, 3}, {5, 6, 7}, {9, 0, 1}};
    auto rc = RabinKarp2D{pattern1, 10};

    const auto octal = read_lines("../resources/octal.txt");

}