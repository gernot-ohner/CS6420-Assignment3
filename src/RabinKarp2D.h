//
// Created by Gernot Ohner on 2024-02-16.
//

#ifndef RABIN_CARP_2D_H
#define RABIN_CARP_2D_H
#include <string>


class RabinKarp2D {
private:
    std::vector<std::string> pattern;
    int pattern_side_length;
    long pattern_hash;
    long large_prime;
    int radix;
    int RM;

    [[nodiscard]] long hash1D(const std::string &key, int m) const;


    static bool check1D(const std::string &txt, const std::string &pattern, int i);
    [[nodiscard]] bool check(const std::vector<std::string> &txt, int column, int row) const;



    static long long_random_prime();

public:
    [[nodiscard]] std::vector<std::string> get_slice(const std::vector<std::string> &input,
        int row, int column, int row_num, int col_num) const;
    [[nodiscard]] long hash(const std::vector<std::string> &key, int m) const;

    explicit RabinKarp2D(const std::vector<std::string> &pat);

    [[nodiscard]] std::pair<int, int> search(const std::vector<std::string> &text) const;
};


#endif //RABIN_CARP_2D_H
