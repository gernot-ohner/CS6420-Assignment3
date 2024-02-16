//
// Created by Gernot Ohner on 2024-02-16.
//

#ifndef KMPPREFIXFUNCTION_H
#define KMPPREFIXFUNCTION_H
#include <string>


class KMPPrefixFunction {
public:
    static std::vector<int> compute_prefix_function(const std::string &p, const int m) {

        std::vector pi(m, 0);
        pi[1] = 0; // redundant
        int k = 0;
        for (int q = 1; q < m; q++) { // Note: q starts from 1 to match pseudocode's 2-to-m (C++ is 0-indexed)
            while (k > 0 && p[k] != p[q]) {
                k = pi[k - 1]; // Adjust k based on the prefix function
            }
            if (p[k] == p[q]) {
                k = k + 1;
            }
            pi[q] = k;
        }
        return pi;
    }
};


#endif //KMPPREFIXFUNCTION_H
