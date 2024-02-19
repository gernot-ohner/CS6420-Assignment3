#include <fstream>
#include <iostream>

#include "alg_strings.h"
#include "RabinKarp2D.h"

void test_pattern(const matrix_t &text,
                  const matrix_t &pattern, int expected_x, int expected_y) {
    const auto &rabin_karp_2d = RabinKarp2D{pattern, 10};
    const auto [x, y] = rabin_karp_2d.search(text);
    std::cout << "ACTUAL:   x: " << x << " y: " << y << std::endl;
    std::cout << "EXPECTED: x: " << expected_x << " y: " << expected_y << std::endl;
}

std::vector<std::vector<char> > read_lines(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::vector<char> > data;

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::vector<char> lineDigits;
            for (const char digit: line) {
                lineDigits.push_back(digit);
            }
            data.push_back(lineDigits);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return data;
}

int main() {

    matrix_t text = {
        {2, 3, 9, 1, 3},
        {5, 1, 2, 3, 4},
        {2, 3, 1, 5, 3},
        {0, 5, 4, 2, 3},
        {1, 0, 6, 1, 5},
    };






    const auto octal = read_lines("../resources/octal.txt");

    matrix_t pattern1 = {{2, 3}, {1, 5}};
    matrix_t pattern2 = {{2, 3}, {5, 1}};
    matrix_t pattern3 = {{0, 5}, {1, 0}};
    matrix_t pattern4 = {{4, 2}, {6, 1}};

    test_pattern(text, pattern1, 2, 1);
    test_pattern(text, pattern2, 0, 0);
    test_pattern(text, pattern3, 0, 3);
    test_pattern(text, pattern4, 2, 3);


    std::cout << "RabinKarp2D --->" << std::endl;
    std::cout << "    Text:" << std::endl;
    for (auto vector : text) {
        std::cout << "    " << std::endl;
        for (char c : vector) {
            std::cout << c + '0';
        }
    }


    // const auto result_false1 = rabin_karp_2d.check(text, 1, 2);
    // const auto result_true = rabin_karp_2d.check(text, 2, 1);
    // const auto result_false2 = rabin_karp_2d.check(text, 2, 2);
    // std::cout << std::boolalpha << result_false1 << " " << result_true << " " << result_false2 << std::endl;


    // const auto slice = rabin_karp_2d.get_slice(text, 1, 2, 2, 2);
    // for (const auto& basic_string : slice) {
    //     std::cout << basic_string << std::endl;
    // }
    //
    // long hash = rabin_karp_2d.hash(slice, 2);
    // std::cout << hash << std::endl;
    //
    // const auto rc = RabinKarp{"asdf"};
    // const auto result = rc.search("thisisasdfatest");
    // std::cout << result << std::endl;
    return 0;
}
