//
// Created by Gernot Ohner on 2024-02-16.
//

#include "RabinKarp2D.h"

#include <random>

long RabinKarp2D::hash(const std::vector<std::string> &key, int m) const {
    return 0l;
}


bool check1D(const std::string &txt, const std::string &pattern, const int i) {
    for (int j = 0; j < pattern.length(); j++) {
        if (pattern[j] != txt[i + j]) {
            return false;
        }
    }

    return true;
}

bool RabinKarp2D::check(const std::vector<std::string> &txt, const int x, const int y) const {
    for (int i = 0; i < this->pattern_side_length; i++) {
        const auto& text_row = txt[i + y];
        const auto& pattern_row = this->pattern[i];
        if (!check1D(text_row, pattern_row, x)) {
            return false;
        }
    }

    return true;
}

long RabinKarp2D::long_random_prime() {
    constexpr int min = 0;
    constexpr int max = 49;
    constexpr long primes[] = {
        2094665479L, 1783990163L, 2094521287L, 2134397081L, 2126326253L,
        1957216747L, 1436547389L, 1428780767L, 2075625529L, 1593123733L,
        2132587157L, 1965562429L, 1164701777L, 1568991883L, 2130061793L,
        1075370311L, 1711832929L, 2054631589L, 1587361861L, 1435348609L,
        1332084959L, 1465215911L, 2088173753L, 1933073123L, 1319415599L,
        1211741129L, 1487473783L, 1656920599L, 1817614213L, 1838911937L,
        1697951429L, 1673793083L, 1971101663L, 1570547117L, 1869368041L,
        1855484017L, 2057695543L, 1806695647L, 2082498797L, 2090345119L,
        1349212999L, 1456810283L, 1271362889L, 1959057733L, 1073964823L,
        1315871351L, 1308843649L, 1543027127L, 1230659387L, 1828780297L
    };

    static std::default_random_engine en;
    en.seed(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> dist{min, max};

    return primes[dist(en)];
}

RabinKarp2D::RabinKarp2D(const std::vector<std::string> &pat): pattern(pat),
                                                               pattern_side_length(pat.size()),
                                                               large_prime(long_random_prime()),
                                                               radix(256),
                                                               RM(0),
                                                               pattern_hash(hash(pat, pattern_side_length)) {
    RM = 1;
    for (int i = 1; i <= pattern_side_length - 1; i++) {
        RM = (radix * RM) % large_prime;
    }
}

std::pair<int, int> RabinKarp2D::search(const std::vector<std::string> &txt) const {
    return std::make_pair(0, 0);
}
