//
// Created by Gernot Ohner on 2024-02-16.
//

#include <gtest/gtest.h>

#include "../src/RabinKarp2D.h"
#include "../src/util.h"

TEST(Test1, BasicAssertions) {

    const matrix_t pattern1 = {{1, 2, 3}, {5, 6, 7}, {9, 0, 1}};
    auto rc = RabinKarp2D{pattern1, 10};

    const auto octal = read_lines("../resources/octal.txt");

}