/**
 * algo to calculate max diff in a vector A such that 
 * for i,j where i < j; max_diff = A[j] - A[i] should be maximum
 * */

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <random> 
#include <string>
#include <vector>

using namespace std;

template<typename Iter>
auto max_diff(Iter beg, Iter end)
{
    using ValueType = typename std::iterator_traits<Iter>::value_type;

    assert(end-beg >= 2);


    Iter curr = next(beg);
    ValueType max_diff = *curr - *beg;
    ValueType min_value = *beg;
    for_each(curr, end, [&max_diff, &min_value](auto&& x){
                max_diff = max(max_diff, x - min_value);
                min_value = min(min_value, x);
            } );

    return max_diff;

}

int main()
{    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    constexpr int MAX = 20;
    uniform_int_distribution<int> dist(1,MAX);

    vector<int> vec(MAX);
    generate(vec.begin(), vec.end(), [&](){ return dist(generator); });

    cout << "vector: " ;
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Max_diff: " << max_diff(vec.begin(), vec.end());
    cout << endl;

    array<int, 10> rev{10,9,8,7,6,5,4,3,2,1};
    cout << "Max_diff: " << max_diff(rev.begin(), rev.end());

}
