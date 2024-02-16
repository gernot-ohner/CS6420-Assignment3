#include <iostream>

#include "alg_strings.h"
#include "RabinKarp2D.h"

int main() {
    const std::vector<std::string> pattern = {"23", "15"};
    const auto &rabin_karp_2d = RabinKarp2D{pattern};

    const std::vector<std::string> text = {
        "23913",
        "51234",
        "23153",
        "05423",
        "10615",
    };

    const auto result_false1 = rabin_karp_2d.check(text, 1, 2);
    const auto result_true = rabin_karp_2d.check(text, 2, 1);
    const auto result_false2 = rabin_karp_2d.check(text, 2, 2);
    std::cout << std::boolalpha << result_false1 << " " << result_true << " " << result_false2 << std::endl;

    const auto [x, y] = rabin_karp_2d.search(text);
    std::cout << "ACTUAL:   x: " << x << " y: " << y << std::endl;
    std::cout << "EXPECTED: x: " << 3 << " y: " << 2 << std::endl;

    const auto rc = RabinKarp{"asdf"};
    const auto result = rc.search("thisisasdfatest");
    std::cout << result << std::endl;
    return 0;
}
