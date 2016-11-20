//
// Created by puneet on 20/11/16.
//

#include <iostream>
#include <string>
#include <vector>
#include "AlgoLib/utils.h"

template<typename T>
auto permutation(const T& str) {
    if (str.size() == 1)  return std::vector<T>{str};

    std::vector<T> ret;
    for (auto itr = str.begin(); itr != str.end(); ++itr) {
        //save str[i]
        auto c = *itr;

        //permuate rest of the string
        T newStr(str);
        newStr.erase(newStr.begin() + std::distance(str.begin(),itr));
        auto newPerm(permutation(newStr));

        for (auto& st : newPerm) {
            st.insert(st.begin(), c);
            ret.push_back(std::move(st));
        }
    }

    return ret;
}

int main() {
    std::vector<std::pair<std::string, std::vector<std::string>>> tests{
            {"",     std::vector < std::string > {}},
            {"a",    {"a"}},
            {"ab",   {"ab",   "ba"}},
            {"abcd", {"abcd", "abdc", "acbd", "acdb",
                             "adbc", "adcb", "bacd", "badc",
                             "bcad", "bcda", "bdac", "bdca",
                             "cabd", "cadb", "cbad", "cbda",
                             "cdab", "cdba", "dabc", "dacb",
                             "dbac", "dbca", "dcab", "dcba"
                     }}
    };

    for(const auto& test : tests) {
        const auto& exp_result = test.second;
        const auto& act_result = permutation(test.first);

        if (exp_result == act_result) {
            std::cout << "PASSED. " << std::endl;
        }
        else {
            std::cout << "FAILED." << std::endl;
            std::cout << " Expected : " << utils::make_range(exp_result.begin(), exp_result.end()) << std::endl;
        }
        std::cout << " Actual : " << utils::make_range(act_result.begin(), act_result.end()) << std::endl;
    }

    return 0;
}
