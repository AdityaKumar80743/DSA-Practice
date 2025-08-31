//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


// Hashing - prestoring and - fetching
// hash array

int freq(vector<int> arr, int target) {
    vector<int> hash((arr.size()+1), 0); // crated vector with all element 0
    for (int i=0; i<=arr.size(); i++) {
        hash[arr[i]] += 1;
    }
    return hash[target];
}

// frequency of alphabets - only small letters
int freqAlpha(string st, int target) {
    vector<int> hash(26,0);
    // int hash[256] = {0}; // better as you have fixed size
    for (int i=0; i<=string.length(); i++) {
        hash[st[i] - "a"] += 1;
    }
    return hash[target];
}

// if consier all the charecters ( 256) 
// make map size 256 
// do not subract "a" - works fine

// int a = "a"; can auto cast it to ascii value

// Instead of using a arr of n size use map (stl) less space
// Map method
int freqMap(vector<int> v, int target) {
    map<int, int> mpp;
    for (int i=0; int<=v.size(); i++) {
        mpp[v[i]] ++;
    }
    return mpp[target];
}
// storing and fectching takes logn time all best avg worst

// better first use unorder map as it takes O(1) time for best and avg
// but O(N) for worst - but rarely happends - due to internal collisions - more than 10^7
// so first use unorderd - if error - use map


// hashing methods
// 1. division method - for arr - (just for understanding)
// if max 10 size arr allowed - create a arr of size 10 -
// then moudul the number in data arr with 10 (% 10) ex. 45%10 = 5
// now store 45 at index 5 
// but if 35 % 10 == also 5
// do chaining in sorted form
// when fetching - can be easily done in minimal time

// collision is case where both 35 and 45 moudulos became equal
// if all collision happend at one index - ex. all values at 9
// now this will take o(n) -- but very rarely -- ex. in unordered map

// # in map we can have pair of any data types 
// but in unordered map it is limited not for all







int main() {
    vector<int> ar = {1,2,3,3,1};
    freq(ar, 3);

    cout << " ended successfuly" << endl;

    return 0;
}
