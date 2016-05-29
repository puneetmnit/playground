/**@file	playground/Algorithms/rotate_id.cpp
 * @author	puneet
 * @version	704
 * @date
 * 	Created:	Sun May 29 17:42:58 2016 \n
 * 	Last Update:	Sun May 29 17:42:58 2016
 * 	Brief : Prgram to right rotate an array
 */

/*===========================================================================*/
/*===============================[ Includes ]===============================*/
/*===========================================================================*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <tuple>
#include <vector>

/*===========================================================================*/
/*===============================[ Includes ]===============================*/
/*===========================================================================*/
using namespace std;

template<typename Cont>
void rotate_i(int i, Cont& vec)
{
    i %= vec.size();

    //it is similar to exchanding the two partitions at index j = end - i
    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), next(vec.begin(), i));
    reverse(next(vec.begin(), i), vec.end());
} 

int main() 
{
    using Tests = tuple<int, vector<int>>;

    vector<Tests> tests;

    //1. single element;
    {
        vector<int> vec{1};
        tests.push_back(make_tuple(0,vec));
        tests.push_back(make_tuple(1,vec));
        tests.push_back(make_tuple(5,vec));
    }

    //2. random elements
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);
        constexpr int MAX = 10;
        uniform_int_distribution<int> dist(1,MAX);

        vector<int> vec(MAX);
        generate(vec.begin(), vec.end(), [&](){ return dist(generator); });

        tests.push_back(make_tuple(0,vec));
        tests.push_back(make_tuple(1,vec));
        tests.push_back(make_tuple(2,vec));
        tests.push_back(make_tuple(3,vec));
        tests.push_back(make_tuple(5,vec));
        tests.push_back(make_tuple(10,vec));
        tests.push_back(make_tuple(12,vec));
        tests.push_back(make_tuple(14,vec));
    }

    for(auto test : tests)
    {
        auto& vec = get<1>(test);
        auto idx = get<0>(test);

        cout << "\nVector: " ; copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << "\nIndex: " << idx;
        rotate_i(get<0>(test), get<1>(test));
        cout << "\nRotate: " ; copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

    } 

    return 0;

}


