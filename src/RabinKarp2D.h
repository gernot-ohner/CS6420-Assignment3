//
// Created by Gernot Ohner on 2024-02-16.
//

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

public:
    long roll_hash(long hash, Coordinate loc, const matrix_t &text, int m, long row_start_hash) const;

    [[nodiscard]] matrix_t get_slice(const matrix_t &input,
                                     int row, int column, int length) const;

    std::vector<T> get_char_slice(const matrix_t &input, int row, int column,
                                     int row_num) const;

    [[nodiscard]] long hash(const matrix_t &key, int m) const;

    explicit RabinKarp2D(const matrix_t &pat, int radix);

    [[nodiscard]] std::pair<int, int> search(const matrix_t &text) const;
};


#endif //RABIN_CARP_2D_H
