/**
 * Generate a list of prime numbes using Eulere's Sive
 * */ 

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
    constexpr int MAXN =10001;
    vector<int> nums(MAXN, 1);

    vector<int> next(MAXN) ; //to get the next non-deleted value
    iota(next.begin(), next.end(), 1);

    vector<int> prev(MAXN) ; //to get the prev non-deleted value
    iota(prev.begin(), prev.end(), -1);

    out(nums);


    int count = 0;
    for (size_t i = 2; i*i < nums.size(); i=next[i]) {
        int j = i;
        //cout << "\nCutting: " ;
        while ( i*j < nums.size() ) {
            //cout << i*j << " ";
            nums[i*j] = 0;

            j = next[j];
            
            if ( nums[j] == 0) {    //now adjust the next and prev
                next[prev[j]] = next[j];
                prev[next[j]] = prev[j];
            }

            ++count;
        } 
        //cout << "num of cuts: " << count;
        out(nums);
        
    }

    //out(nums);
    cout << endl << "comparisons: " << count << endl;

    //out(nums);

    return 0;
} 
