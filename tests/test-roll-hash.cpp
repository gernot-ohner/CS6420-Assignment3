//
// Created by Gernot Ohner on 2024-02-16.
//
#include <gtest/gtest.h>

#include "../src/RabinKarp2D.h"


TEST(RollHashMinimal, BasicAssertions) {
    const matrix_t text = {
        {2, 3, 9},
        {5, 1, 4},
        {7, 8, 0},
    };

    matrix_t pattern1 = {{2, 3}, {5, 1}};
    auto rc = RabinKarp2D{pattern1, 10};

    const auto hash = rc.hash(pattern1, 2);
    const auto row_start_hash = hash;

    const auto res_right1 = rc.roll_hash(hash, {0, 0}, text, 2, row_start_hash);
    const auto res_down1 = rc.roll_hash(res_right1, {0, 1}, text, 2, row_start_hash);
    const auto res_down1_right1 = rc.roll_hash(res_down1, {1, 0}, text, 2, res_down1);

    EXPECT_EQ(hash, 2531);
    EXPECT_EQ(res_right1, 3194);
    EXPECT_EQ(res_down1, 5718);
    EXPECT_EQ(res_down1_right1, 1840);
}

TEST(RollHash3N, BasicAssertions) {
    const matrix_t text = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6},
    };

    const matrix_t pattern1 = {{1, 2, 3}, {5, 6, 7}, {9, 0, 1}};
    auto rc = RabinKarp2D{pattern1, 10};
    constexpr int m = 3;

    const auto hash = rc.hash(pattern1, m);
    const auto row_start_hash = hash;

    const auto res_right1 = rc.roll_hash(hash, {0, 0}, text, m, row_start_hash);
    const auto res_down1 = rc.roll_hash(res_right1, {0, 1}, text, m, row_start_hash);
    const auto res_down1_right1 = rc.roll_hash(res_down1, {1, 0}, text, m, res_down1);

    EXPECT_EQ(hash, 159'260'371);
    EXPECT_EQ(res_right1, 260'371'482);
    EXPECT_EQ(res_down1, 593'604'715);
    EXPECT_EQ(res_down1_right1, 604'715'826);
}

TEST(RollHash4N, BasicAssertions) {
    const matrix_t text = {
        {2, 3, 9, 1, 3},
        {5, 1, 2, 3, 4},
        {2, 3, 1, 5, 3},
        {0, 5, 4, 2, 3},
        {1, 0, 6, 1, 5},
    };

    const matrix_t pattern1 = {{2, 3, 9, 1}, {5, 1, 2, 3}, {2, 3, 1, 5}, {0, 5, 4, 2}};
    auto rc = RabinKarp2D{pattern1, 10};
    constexpr int m = 4;

    const auto hash = rc.hash(pattern1, m);
    const auto row_start_hash = hash;

    const auto res_right1 = rc.roll_hash(hash, {0, 0}, text, m, row_start_hash);
    const auto res_down1 = rc.roll_hash(res_right1, {0, 1}, text, m, row_start_hash);
    const auto res_down1_right1 = rc.roll_hash(res_down1, {1, 0}, text, m, res_down1);

    EXPECT_EQ(hash, 2520'3135'9214'1352);
    EXPECT_EQ(res_right1, 3135'9214'1352'3433);
    EXPECT_EQ(res_down1, 5201'1350'2146'3521);
    EXPECT_EQ(res_down1_right1, 1350'2146'3521'4335);
}
