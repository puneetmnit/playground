//
// Created by puneet on 19/11/16.
//

#include <string>
#include <vector>
#include <iostream>
#include "AlgoLib/utils.h"

using namespace std;


vector<string> strTokenize(const string& s, char token=' ') {
    vector<string> ret;
    auto start = s.begin();

    while (start != s.end()) {
        auto end = std::find(start, s.end(), token);
        ret.emplace_back(start, end);
        start = end;
        if (start != s.end()) ++start;
    }
    return ret;
}


int main() {
    char token = '.';
    vector<pair<string, vector<string>>> tests{
            {"", {}},
            {"asdf", { "asdf"}},
            {".", {""}},
            {"...", {"","",""}},
            {".a", {"","a"}},
            {".a.", {"","a"}},
            {"a.", {"a"}},
            {"a.b.c.", {"a","b","c"}},
            {".a.b.c", {"","a","b","c"}},
            {".a..b.dsf.ef...a.", {"","a","","b","dsf","ef","","","a"}}
    };


    std::for_each(tests.begin(), tests.end(), [token](const auto& s) {
        decltype(auto) act_res = strTokenize(s.first, token);
        if (act_res == s.second) {
            cout << "Passed." << endl;
        }
        else {
            cout << "Failed. " << endl
                 << " Expected: " << utils::make_range(s.second.begin(), s.second.end()) << endl;

        }
        cout << " Actual : " << utils::make_range(act_res.begin(), act_res.end()) << endl;
    });
}

