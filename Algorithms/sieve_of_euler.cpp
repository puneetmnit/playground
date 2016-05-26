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

int main(int argc, char** argv) 
{
    if (argc != 2)
    {
        cout << "Incorrect arguments: " << endl;
        cout << "Usage: " << argv[0] << " <max num>" << endl;
        return 1;
    }
    
    int n = atoi( argv[1] );
    vector<int> nums(n, 1);

    vector<int> next(n) ; //to get the next non-deleted value
    iota(next.begin(), next.end(), 1);

    vector<int> prev(n) ; //to get the prev non-deleted value
    iota(prev.begin(), prev.end(), -1);

    //out(nums);


    //int count = 0;
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

            //++count;
        } 
        //cout << "num of cuts: " << count;
        //out(nums);
        
    }

    out(nums);
    //cout << endl << "comparisons: " << count << endl;


    return 0;
} 
