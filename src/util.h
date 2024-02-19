//
// Created by Gernot Ohner on 2024-02-18.
//

#ifndef UTIL_H
#define UTIL_H
#include <fstream>
#include <iostream>
#include <ostream>

inline void test_pattern(const matrix_t &text,
                         const matrix_t &pattern, int expected_x, int expected_y) {
    const auto &rabin_karp_2d = RabinKarp2D{pattern, 10};
    const auto [x, y] = rabin_karp_2d.search(text);
    std::cout << "    Pattern found at row, column index: "
            << std::endl << "    {" << x << ", " << y << "}" << std::endl;
}

inline void print_matrix(const matrix_t &text) {
    for (const auto &vector: text) {
        std::cout << "    ";
        for (const auto c: vector) {
            std::cout << static_cast<int>(c);
        }
        std::cout << std::endl;
    }
}

inline std::vector<std::vector<T> > read_lines(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::vector<T> > data;

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::vector<T> lineDigits;
            for (const auto digit: line) {
                lineDigits.push_back(digit - '0');
            }
            data.push_back(lineDigits);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return data;
}

#endif //UTIL_H
