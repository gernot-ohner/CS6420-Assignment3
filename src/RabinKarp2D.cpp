//
// Created by Gernot Ohner on 2024-02-16.
//

#include "RabinKarp2D.h"

#include <iostream>
#include <random>

long RabinKarp2D::hash1D(const std::vector<T> &key, int m) const {
    long h = 0;
    for (int j = 0; j < m; j++) {
        h = (radix * h + key[j]) % large_prime;
    }
    return h;
}


long RabinKarp2D::roll_hash(long hash, const Coordinate loc, const matrix_t &text, const int m, long row_start_hash) const {

    if (loc.col + m >= text.size()) {
        // remove old row contribution
        long old_row_contribution = 0;
        for (int j = 0; j < m; j = j + 1) {
            const auto val = text[loc.row][j];
            const auto factor = std::pow(radix, m*m - m*j - 1);
            old_row_contribution += val * factor;
        }
        row_start_hash -= old_row_contribution;

        row_start_hash *= radix;

        // Add the contribution of the entering row
        long new_row_contrib = 0;
        for (int j = 0; j < m; ++j) {
            const auto val = text[loc.row + m][j];
            const auto factor = std::pow(radix, m*m - m*(j+1));
            new_row_contrib += val * factor;
        }
        row_start_hash += new_row_contrib;

        return row_start_hash;

    } else {
        long pow = std::pow(radix, m * m - m);
        hash = hash % pow;
        for (int i = 0; i < m; ++i) {
            hash *= radix;
            const auto x = text[loc.row + i][loc.col + m];
            hash += x;
        }
    }

    return hash;
}

long RabinKarp2D::hash(const std::vector<std::vector<T> > &key, int m) const {
    long hash = 0;
    std::vector<long> items{};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; ++j) {
            // TODO add moduloing!
            const auto x = key[j][i];
            hash = hash * radix + x;
        }
    }

    return hash;
}

bool RabinKarp2D::check1D(const std::vector<T> &txt, const std::vector<T> &pattern, const int i) {
    for (int j = 0; j < pattern.size(); j++) {
        if (pattern[j] != txt[i + j]) {
            return false;
        }
    }

    return true;
}

bool RabinKarp2D::check(const matrix_t &txt, const int column, const int row) const {
    for (int i = 0; i < this->pattern_side_length; i++) {
        const auto &text_row = txt[row + i];
        const auto &pattern_row = this->pattern[i];
        if (!check1D(text_row, pattern_row, column)) {
            return false;
        }
    }

    return true;
}

std::vector<T> vector_substr(const std::vector<T> &vec, size_t start, size_t len) {
    if (start > vec.size()) {
        throw std::out_of_range("Start index is out of range");
    }

    auto end = start + len;
    if (end > vec.size()) {
        end = vec.size();
    }

    return std::vector<T>(vec.begin() + start, vec.begin() + end);
}

std::vector<std::vector<T> > RabinKarp2D::get_slice(const matrix_t &input,
                                                       const int row,
                                                       const int column,
                                                       const int length
) const {
    std::vector<std::vector<T> > result{};
    for (int i = 0; i < length; i++) {
        const auto &input_row = input[i + row];
        const auto &input_slice = vector_substr(input_row, column, length);
        result.push_back(input_slice);
    }
    return result;
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

RabinKarp2D::RabinKarp2D(const matrix_t &pat, int radix): pattern(pat),
    pattern_side_length(pat.size()),
    large_prime(long_random_prime()),
    radix(radix),
    RM(0) {
    pattern_hash = hash(pat, pattern_side_length);
    RM = 1;
    for (int i = 1; i <= pattern_side_length - 1; i++) {
        RM = (radix * RM) % large_prime;
    }
}


std::pair<int, int> RabinKarp2D::search(const matrix_t &text) const {
    const auto n = text.size();
    if (n < pattern_side_length) return {n, n};

    long text_hash = hash(get_slice(text, 0, 0, pattern_side_length), pattern_side_length);
    if ((pattern_hash == text_hash) && check(text, 0, 0))
        return {0, 0};

    for (int row = 0; row <= n - pattern_side_length; row++) {
        const long row_start_hash = text_hash;
        for (int column = 0; column <= n - pattern_side_length; column++) {
            if ((pattern_hash == text_hash) && check(text, column, row)) {
                return {column, row};
            }
            text_hash = roll_hash(text_hash, {row, column}, text, pattern_side_length, row_start_hash);
        }
    }
    return {n, n}; // no match
}