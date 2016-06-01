/**@file	playground/Algorithms/merge_arrays.cpp
 * @author	puneet
 * @version	704
 * @date
 * 	Created:	Wed Jun  1 23:04:52 2016 \n
 * 	Last Update:	Wed Jun  1 23:04:52 2016
 *
 * 	This merges the two sorted array with O(1) space complexity
 */

/*===========================================================================*/
/*===============================[ Includes ]===============================*/
/*===========================================================================*/
 
#include<algorithm>
#include<iostream>
#include<iterator>
#include <utility>
#include<vector>

#include "lib/utils.h"

/*===========================================================================*/
/*===============================[ Includes ]===============================*/
/*===========================================================================*/
using namespace std;

template<typename T>
inline void print(const string& str, T type)
{
    typedef typename T::value_type Value_type;
    cout << str;
    copy(type.begin(), type.end(), ostream_iterator<Value_type>(cout, " "));
    cout << endl;
}

template<typename T>
void merge(T& vec1, T& vec2)
{
    //vec1 should be able to contain all elements
    vec1.resize(vec1.size() + vec2.size()); 

    //write iterator
    auto w_iter = vec1.rbegin();

    //read iterator
    auto vec1_iter = next(vec1.rbegin(), vec2.size());
    auto vec2_iter = vec2.rbegin();

    //fill vec1 from last
    while (vec1_iter != vec1.rend() && vec2_iter != vec2.rend())
    {
        if (*vec1_iter > *vec2_iter)
        {
            *w_iter++ = *vec1_iter++;
        }
        else
        {
            *w_iter++ = *vec2_iter++;
        }
    }

    //fill remaining values
    while (vec2_iter != vec2.rend())
    {
        *w_iter++ = *vec2_iter++;
    }

    //same loop for vec1 is not required, as that is already part of the result.
    
}

int main()
{
    //Tests
    vector<pair<vector<int>, vector<int>>> tests;

    //1. both empty
    {
        vector<int> vec1;
        tests.push_back(std::make_pair(vec1, vec1));
    }
    
    // 2. vec1 empty
    {
        vector<int> vec1;
        vector<int> vec2(10);
        utils::random_fill(vec2.begin(), vec2.end(), 1, 99);
        sort(vec2.begin(), vec2.end());
        tests.push_back(std::make_pair(vec1, vec2));
    // 3. vec2 empty
        tests.push_back(std::make_pair(vec2, vec1));
    }

    // 4. all elements of vec 1 greater than vec2
    {
        vector<int> vec1(8);
        vector<int> vec2(10);

        utils::random_fill(vec1.begin(), vec1.end(), 51, 99);
        sort(vec1.begin(), vec1.end());

        utils::random_fill(vec2.begin(), vec2.end(), 1, 50);
        sort(vec2.begin(), vec2.end());

        tests.push_back(std::make_pair(vec1, vec2));
        
    // 5. all elements of vec 2 greater than vec1
        tests.push_back(std::make_pair(vec2, vec1));
    }
    
    // 6. same size
    {
        vector<int> vec1(10);
        vector<int> vec2(10);

        utils::random_fill(vec1.begin(), vec1.end(), 1, 99);
        sort(vec1.begin(), vec1.end());

        utils::random_fill(vec2.begin(), vec2.end(), 1, 99);
        sort(vec2.begin(), vec2.end());

        tests.push_back(std::make_pair(vec1, vec2));
     }
     
    // 7. |vec1| > |vec2|
    {
        vector<int> vec1(10);
        vector<int> vec2(5);

        utils::random_fill(vec1.begin(), vec1.end(), 1, 99);
        sort(vec1.begin(), vec1.end());

        utils::random_fill(vec2.begin(), vec2.end(), 1, 99);
        sort(vec2.begin(), vec2.end());

        tests.push_back(std::make_pair(vec1, vec2));
    // 7. |vec2| > |vec1|
        tests.push_back(std::make_pair(vec2, vec1));
     }


    for(auto&& test: tests)
    {
        auto&& vec1 = test.first;
        auto && vec2 = test.second;

        print("Vector1: ", vec1);
        print("Vector2: ", vec2);

        merge(vec1, vec2);
        
        print("Result : ", vec1);
        cout << endl;
    }

} 
