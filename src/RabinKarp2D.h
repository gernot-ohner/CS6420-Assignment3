// Gernot F. Ohner
// CS 6420
// Assignment #3
// Instructor: Dr. Rague
// Due: 02/18/24
// Version: 1.0
// Created: 2024-02-18.
// -----------------------------------------------------------------
// This file contains the header information for the 2D rabin karp
// algorithm.
// -----------------------------------------------------------------

#ifndef RABIN_CARP_2D_H
#define RABIN_CARP_2D_H
#include <string>

typedef uint8_t T;
typedef std::vector<std::vector<T> > matrix_t;

struct Coordinate {
    int row;
    int col;
};

class RabinKarp2D {
private:
    matrix_t pattern;
    int pattern_side_length;
    long pattern_hash;
    long large_prime;
    int radix;
    int RM;

    [[nodiscard]] long hash1D(const std::vector<T> &key, int m) const;


    static bool check1D(const std::vector<T> &txt, const std::vector<T> &pattern, int i);

    [[nodiscard]] bool check(const matrix_t &txt, int column, int row) const;

    static long long_random_prime();

    [[nodiscard]] long roll_hash(long hash, Coordinate loc, const matrix_t &text, int m, long row_start_hash) const;

    [[nodiscard]] matrix_t get_slice(const matrix_t &input,
                                     int row, int column, int length) const;

    [[nodiscard]] long hash(const matrix_t &key, int m) const;

public:
    explicit RabinKarp2D(const matrix_t &pat, int radix);

    [[nodiscard]] Coordinate search(const matrix_t &text) const;
};


#endif //RABIN_CARP_2D_H
