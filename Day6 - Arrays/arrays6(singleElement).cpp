#include <iostream>
#include <map>

using namespace std;

// ---------------- MAXIMUM CONSECUTIVE OF ONE'S------
// PROBLEM: find the maximum number of times (1) appears in continues order

// --- brute force
// using count
int maxRepeat(int arr[], int n) {
    int count = 0;
    
    for (int i=0; i<n; i++) {
        if (arr[i] == 1) {
            int ccount = 0;
            for (int j=i; j<n; j++) {
                if (arr[j] != 1) {
                    break; // no continuos (1) so go to next element
                } else {
                    ccount++;
                    count = max(count, ccount); // upadate count
                }
            }
        }
    }
    return count;
}
// TC - O(n^2)
// SC - O(n)

// --- optimal 
// using pointers
int maxRepeat2(int arr[], int n) {
    int maxRep = 0;
    int curRep = 0;
    
    for (int i=0; i<n; i++) {
        if (arr[i] == 1) {
            curRep++;
            maxRep = max(curRep, maxRep);
        } else curRep = 0;
    }
    return maxRep;
}
// TC - O(n)
// SC - O(1)


// ----------------- SINGLE ELEMENT -----------
// problem all the elements in the array appears twice expect one elemnt 

// brute force 
int single(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<n; j++) {
            if (arr[j] == arr[i]) count++;
        }
        if (count <= 1) return arr[i];
    }
    return -1;
}
// TC - O(n^2)
// SC - O(1)

// --- better 
// using hash
int single2(int arr[], int n) {
    map<int, int> m;
    
    for (int i=0; i<n; i++) m[arr[i]]++;
    for (auto [num, freq]: m) {
        if (freq == 1) return num;
    }
    return -1;
}
// unorder map for more efficiency 
// TC - O(n + n/2 +1)
// SC - O(n/2 +1 )

// --- optimal
// using xor
// all twice repeating number will cancel each other only the single element will remain
int single3(int arr[], int n) {
    int res = 0;
    for (int i=0; i<n; i++) {
        res ^= arr[i];
    }
    return res;
}
// TC - O(n)
// SC - O(1)

int main() {
    int arr[7] = {1,1,0,2,2,3,3};
    cout << single3(arr, 7);
    
    return 0;
}
