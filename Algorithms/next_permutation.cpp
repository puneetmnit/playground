/**@file	/Users/puneet/Documents/technical/projects/playground/Algorithms/next_permutation.cpp
 * @author	puneet
 * @version	704
 * @date
 * 	Created:	Sun May 29 15:45:41 2016 \n
 * 	Last Update:	Sun May 29 15:45:41 2016
 */

/*===========================================================================*/
/*===============================[ Incudes ]===============================*/
/*===========================================================================*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

/*===========================================================================*/
/*===============================[ Code ]===============================*/
/*===========================================================================*/

using namespace std;

template<typename Container>
void next_permutation(Container& c)
{
    //return single element container as it is
    if ( c.size() < 2) return ;
    
    //1. search backwards i,j such that A[i]<A[j] for i<j
    auto prev = c.rbegin();
    decltype(c.rbegin()) i;
    for( i=next(c.rbegin()); i != c.rend(); ++i)
    {
        if (*i < *prev) {
            break;  //i is the index after which we need to change the permutation
        }
        prev = i;
    }

    if ( i == c.rend() ) 
    {
        // it already is the largest. Return
        return;
    }


    //2. search backwards for a j greater than *i
    auto j = find_if( c.rbegin(), i, [i](auto x) {
                return x > *i;
            } );

    //3. swap i and j
    swap(*i, *j);

    //4. reverse all sequence after i
    reverse(next(c.begin(), distance(i,c.rend())), c.end());

}




int main() 
{
    vector<vector<int>> tests;

    //1. single
    tests.push_back({1});

    //2. smallest
    tests.push_back({1,2,3,4});

    //3. largest
    tests.push_back({4,3,2,1});

    //4. random
    vector<int> vec(5);

    //generate random vector
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine gen(seed);
    uniform_int_distribution<int> dist(1,5);

    for (auto i = 0 ; i < 3; ++i) 
    {
        generate(begin(vec), end(vec), [&gen, &dist] { return dist(gen);});
        tests.push_back(vec);
    }

    //results
    for ( auto& vec : tests)
    {
        cout << "\nVector: ";
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        next_permutation(vec);
        cout << "Next: ";
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

    }


    return 0;
}

