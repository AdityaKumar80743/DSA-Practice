#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ================== NEXT PERMUTATION ======================
// PROBLEM: return the next permutation of the given array in dictinary order

// --- brute
// 1. generate all permutatons in order
// 2. linear search to get the given permutaion
// 3. return the next permutaion after the given permutaion
// TC - O(n*n!) 

// ---- print all permutations
// initial values of idx is 0
void permutaion(vector<int> res, vector<int> arr, int idx) {
    // base case - idx = arr.size()
    if (idx == arr.size()) {
        res.push_back(arr);
        return;
    }

    for (int i=0; i<arr.size(); i++) {
        swap(arr[i], arr[idx]);

        permutaion(res, arr, idx+1);

        swap(arr[i], arr[idx]); // restore the swap previously made
    }
}

// --- better 
// using STL for permutations

// --- optimal
vector<int> nextPermutation(vector<int> arr) {
    int n = arr.size();
    int ind = -1; // break point

    // step1. find the break point 
    for (int i=n-2; i>=0; i--) {
        if (arr[i] < arr[i+1]) {
            ind = i; // break point i
            break;
        }
    }
    // if break point does not exit 
    if (ind == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    // step 2. find the next greatest element
    for (int i=n-1; i>ind; i--) {
        if (arr[i] > arr[ind]) {
            swap(arr[i], arr[ind]);
            break;
        }
    }
    // step3. reverse the right half
    reverse(arr.begin()+ind+1, arr.end());

    return arr;
}
// TC - O(n) 
// SC - 

int main() {
    vector<int> arr = {1,2,3,4,5};
    vector<int> ans = nextPermutation(arr);

    for (auto it:ans) {
        cout << it << " ";
    }


    return 0;

}
