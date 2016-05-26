/**
 * Generate list of prime numbers using Sieve of Eratosthenes
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std ;


void out(std::vector<int>& vec)
{
    cout << endl << "Result: " ;
    for (size_t i =2 ; i < vec.size(); ++i) {
        if (vec[i] == 1) {
            cout << i << " " ;
        }
    } 
}

int main() {
    constexpr int MAXN =101;
    vector<int> nums(MAXN, 1);

    out(nums);

    nums[0] = nums[1] = 0;


    int count = 0;
    for (size_t i = 2; i*i < nums.size(); ++i) {

        if ( nums[i] == 1) {
            size_t j = i*i;
            cout << "\nCutting: " ;
            while ( j < nums.size() ) {
                cout << j << " ";
                nums[j] = 0;

                j += i;

                ++count;
            } 
            //cout << "num of cuts: " << count;
            out(nums);

        }

    }

    //out(nums);
    cout << endl << "comparisons: " << count << endl;

    //out(nums);

    return 0;
} 
