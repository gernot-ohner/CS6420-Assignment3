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

    [[nodiscard]] long hash(const std::vector<std::string> &key, int m) const;

    // [[nodiscard]] bool check(const std::vector<std::string> &txt, int x, int y) const;

    static long long_random_prime();

public:
    [[nodiscard]] bool check(const std::vector<std::string> &txt, int x, int y) const;
    explicit RabinKarp2D(const std::vector<std::string> &pat);

    [[nodiscard]] std::pair<int, int> search(const std::vector<std::string> &txt) const;
};


#endif //RABIN_CARP_2D_H
