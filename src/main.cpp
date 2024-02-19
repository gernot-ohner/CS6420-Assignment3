#include <fstream>
#include <iostream>

#include "alg_strings.h"
#include "RabinKarp2D.h"

void test_pattern(const matrix_t &text,
                  const matrix_t &pattern, int expected_x, int expected_y) {
    const auto &rabin_karp_2d = RabinKarp2D{pattern, 10};
    const auto [x, y] = rabin_karp_2d.search(text);
    std::cout << "    Pattern found at row, column index: "
    << std::endl << "    {" << x << ", " << y << "}" << std::endl;
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

void print_matrix(matrix_t text) {
    for (const auto &vector: text) {
        std::cout << "    ";
        for (const auto c: vector) {
            std::cout << static_cast<int>(c);
        }
        std::cout << std::endl;
    }
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
    std::vector patterns{pattern1, pattern2, pattern3, pattern4};



    std::cout << "RabinKarp2D --->" << std::endl;
    std::cout << "    Text:" << std::endl;
    print_matrix(text);
    std::cout << std::endl;
    std::cout << "    Pattern 1:" << std::endl;
    print_matrix(pattern1);
    test_pattern(text, pattern1, 2, 1);
    std::cout << std::endl;

    std::cout << "    Pattern 2:" << std::endl;
    print_matrix(pattern2);
    test_pattern(text, pattern2, 0, 0);
    std::cout << std::endl;

    std::cout << "    Pattern 3:" << std::endl;
    print_matrix(pattern3);
    test_pattern(text, pattern3, 0, 3);
    std::cout << std::endl;

    std::cout << "    Pattern 4:" << std::endl;
    print_matrix(pattern4);
    test_pattern(text, pattern4, 2, 3);
    std::cout << std::endl;



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
