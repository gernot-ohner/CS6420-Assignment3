#include <iostream>

#include "alg_strings.h"
#include "RabinKarp2D.h"

void test_pattern(const std::vector<std::string> &text,
                  const std::vector<std::string> &pattern, int expected_x, int expected_y) {
    const auto &rabin_karp_2d = RabinKarp2D{pattern};
    const auto [x, y] = rabin_karp_2d.search(text);
    std::cout << "ACTUAL:   x: " << x << " y: " << y << std::endl;
    std::cout << "EXPECTED: x: " << expected_x << " y: " << expected_y << std::endl;
}

int main() {
    const std::vector<std::string> text = {
        "23913",
        "51234",
        "23153",
        "05423",
        "10615",
    };
    const std::vector<std::string> pattern1 = {"23", "51"};
    const std::vector<std::string> pattern2 = {"23", "15"};
    // const std::vector<std::string> pattern3 = {"23", "15"};
    // const std::vector<std::string> pattern4 = {"23", "15"};
    test_pattern(text, pattern1, 0, 0);
    test_pattern(text, pattern2, 2, 1);


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
