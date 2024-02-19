// Gernot F. Ohner
// CS 6420
// Assignment #3
// Instructor: Dr. Rague
// Due: 02/18/24
// Version: 1.0
// Created: 2024-02-18.
// -----------------------------------------------------------------
// This program compares the brute force and improved algorithms for
// the four sum problem implemented in FourSum.cpp.
// -----------------------------------------------------------------

#include <fstream>
#include <iostream>

#include "alg_strings.h"
#include "RabinKarp2D.h"
#include "util.h"

int main() {
    const matrix_t text = {
        {2, 3, 9, 1, 3},
        {5, 1, 2, 3, 4},
        {2, 3, 1, 5, 3},
        {0, 5, 4, 2, 3},
        {1, 0, 6, 1, 5},
    };

    const matrix_t pattern1 = {{2, 3}, {1, 5}};
    const matrix_t pattern2 = {{2, 3}, {5, 1}};
    const matrix_t pattern3 = {{0, 5}, {1, 0}};
    const matrix_t pattern4 = {{4, 2}, {6, 1}};

    std::cout << "RabinKarp2D --->" << std::endl;
    std::cout << "    Text:" << std::endl;
    print_matrix(text);
    std::cout << std::endl;
    std::cout << "    Pattern 1:" << std::endl;
    print_matrix(pattern1);
    test_pattern(text, pattern1);
    std::cout << std::endl;

    std::cout << "    Pattern 2:" << std::endl;
    print_matrix(pattern2);
    test_pattern(text, pattern2);
    std::cout << std::endl;

    std::cout << "    Pattern 3:" << std::endl;
    print_matrix(pattern3);
    test_pattern(text, pattern3);
    std::cout << std::endl;

    std::cout << "    Pattern 4:" << std::endl;
    print_matrix(pattern4);
    test_pattern(text, pattern4);
    std::cout << std::endl;

    return 0;
}
