//
// Created by Gernot Ohner on 2024-02-16.
//

#include "RabinKarp2D.h"

#include <iostream>
#include <random>

long RabinKarp2D::hash1D(const std::string &key, int m) const {
    long h = 0;
    for (int j = 0; j < m; j++) {
        h = (radix * h + key[j]) % large_prime;
    }
    return h;
}

long RabinKarp2D::hash(const std::vector<std::string> &key, int m) const {
    long hash = 0;
    for (int i = 0; i < m; i++) {
        // TODO this is the simplest aggregation function - does it work?
        hash += hash1D(key[i], m);
    }
    return hash;
}


bool RabinKarp2D::check1D(const std::string &txt, const std::string &pattern, const int i) {
    for (int j = 0; j < pattern.length(); j++) {
        if (pattern[j] != txt[i + j]) {
            return false;
        }
    }

    return true;
}

bool RabinKarp2D::check(const std::vector<std::string> &txt, const int column, const int row) const {
    for (int i = 0; i < this->pattern_side_length; i++) {
        const auto &text_row = txt[row + i];
        const auto &pattern_row = this->pattern[i];
        if (!check1D(text_row, pattern_row, column)) {
            return false;
        }
    }

    return true;
}

std::vector<std::string> RabinKarp2D::get_slice(const std::vector<std::string> &input,
                                                const int row,
                                                const int column,
                                                const int row_num,
                                                const int col_num
) const {
    std::vector<std::string> result{};
    for (int i = 0; i < row_num; i++) {
        const auto &input_row = input[i + row];
        const auto &input_slice = input_row.substr(column, col_num);
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

RabinKarp2D::RabinKarp2D(const std::vector<std::string> &pat): pattern(pat),
                                                               pattern_side_length(pat.size()),
                                                               large_prime(long_random_prime()),
                                                               radix(256),
                                                               RM(0) {
    pattern_hash = hash(pat, pattern_side_length);
    RM = 1;
    for (int i = 1; i <= pattern_side_length - 1; i++) {
        RM = (radix * RM) % large_prime;
    }
}

std::pair<int, int> RabinKarp2D::search(const std::vector<std::string> &text) const {
    const auto n = text.size();
    if (n < pattern_side_length) return {n, n};

    long text_hash = hash(get_slice(text, 0, 0, pattern_side_length, pattern_side_length), pattern_side_length);
    if ((pattern_hash == text_hash) && check(text, 0, 0))
        return {0, 0};

    // TODO this doesn't loop often enough
    std::cout << "pattern hash: " << pattern_hash << std::endl;
    for (int row = 0; row <= n - pattern_side_length; row++) {
        for (int column = pattern_side_length; column < n; column++) {
            auto to_subtract = 0;
            const auto basic_strings1 = get_slice(text, row, column - pattern_side_length, pattern_side_length, 1);
            for (const auto &s: basic_strings1) {
                to_subtract += std::stoi(s);
            }
            to_subtract *= RM;

            auto to_add = 0;
            const auto basic_strings2 = get_slice(text, row, column, pattern_side_length, 1);
            for (const auto &s: basic_strings2) {
                to_add += std::stoi(s);
            }

            text_hash = (text_hash + large_prime - to_subtract % large_prime) % large_prime;
            text_hash = (text_hash * radix + to_add) % large_prime;

            // match
            int column_offset = column - pattern_side_length + 1;
            const bool pattern_hash_match = pattern_hash == text_hash;
            const bool check_match = check(text, column_offset, row);
            std::cout << std::boolalpha << "row: " << row << ", column: " << column
                    << ": hash match: " << pattern_hash_match
                    << ", check match: " << check_match
                    << ", text hash: " << text_hash
                    << std::endl;;
            if (pattern_hash_match && check_match) {
                return {column_offset, row};
            }
            // END
        }
    }


    return {n, n}; // no match
}

// 1D rabin karp search function
// int RabinKarp::search(const std::string &txt) const {
//   int n = txt.length();
//   if (n < m) return n;
//   long txt_hash = hash(txt, m);
//
//   // check for match at offset 0
//   if ((pat_hash == txt_hash) && check(txt, 0))
//     return 0;
//
//   // check for hash match; if hash match, check for exact match
//   for (int i = m; i < n; i++) {
//     // Remove leading digit, add trailing digit, check for match.
//     txt_hash = (txt_hash + q - RM * txt[i - m] % q) % q;
//     txt_hash = (txt_hash * R + txt[i]) % q;
//
//     // match
//     int offset = i - m + 1;
//     if ((pat_hash == txt_hash) && check(txt, offset)){
//       return offset;
//     }
//   }
//
//   return n; // no match
// }
