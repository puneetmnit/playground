//
// Created by puneet on 02/10/16.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "AlgoLib/trie.h"

void count_leafs(Trie::Node* root, int& count) {
    if (root->isLeaf == 1) {
        count += 1;
    }
    for (const auto &c : root->children) {
        count_leafs(c.second, count);
    }
}

int partial_match(Trie::Node* root, const std::string& str) {
    int count = 0;
    Trie::Node* p = root;
    for (auto c : str) {
        auto found = p->children.find(c);
        if (found == p->children.end()) return 0;
        p = found->second;
    }
    count_leafs(p, count);
    return count;

}

int main() {
    std::vector<std::string> names {"puneet", "pune", "punit", "agra", "agrawal" , "wale"};
    std::vector<std::pair<std::string, int>> results { {"a", 2},
                                                       {"agraw",1},
                                                       {"p",3},
                                                       {"w",1},
                                                      {"pun", 3},
                                                      {"pune",2},
                                                      {"wale",1},
                                                      {"walee",0},
                                                      {"punnet",0},
                                                      {"xyz",0}};

    Trie::Node* root = new Trie::Node();
    std::for_each(std::begin(names), std::end(names), [&root](auto x){Trie::insert(root, x);});

    auto tests = results.size();
    auto test_p = 0;
    auto test_f = 0;

    for (auto r : results) {
        std::cout << "Matching: " << r.first << std::endl;
        auto ret = partial_match(root, r.first);
        if (ret == r.second) {
            std::cout << "Passed" << std::endl;
            ++test_p;
        }
        else {
            std::cout << "Failed. Expected: " << r.second << " Actual : " << ret << std::endl;
            ++test_f;
        }
    }
    std::cout << "Total: " << tests << std::endl;
    std::cout << " Passed: " << test_p << std::endl;
    std::cout << " Failed: " << test_f << std::endl;
}
