/**
 * algo to calculate max diff in a vector A such that 
 * for i,j where i < j; max_diff = A[j] - A[i] should be maximum
 * */

#include <algorithm>
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

    if (end - beg < 2) {
        return 0;
    }

    Iter next = next(beg);
    ValueType max_diff = *next - *beg;
    ValueType min_value = *beg;
    while (++next != end) {
        max_diff = max(max_diff, *next - min_value);
        min_value = min(min_value, *next):
    }

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

}
