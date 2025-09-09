#include <iostream>

using namespace std;

// --------------- TWO SUM ------------
// PROBLEM: find if there exit two numbers in an array which has sum equal to k
// VARIATIONS: return yes / no  -- or -- the indexes the values are present which sum up to k



// --- brute force
bool twoSum(int arr[], int n, int k) {
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (arr[i] + arr[j] == k) return true;
        }
    }
    return false;
}
// TC - O(n^2)
// SC - O(1)

// using sort and pointers
// --- optimal is returning result in bool(true/false)
bool twoSum2(int arr[], int n, int k) {
    sort(arr.begin(), arr.end());
    int start = 0, end = n-1;

    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum < k) start++;
        else if (sum > k) end--;
        else return true;
    }
    return false;
}
// TC - O(n + nlogn) 
// SC - O(1)
// here we have changed the array so to preserve it, we can keep a copy of the array
// so SC - o(n)


// using hashmap
bool twoSum3(int arr[], int n, int k) {
    map<int, int> hash;
    for (int i=0; i<n; i++) {
        int needed = k - arr[i];
        if (hash.find(needed) != hash.end()) {
            return true;
        }
        hash[arr[i]] = i;
    }
    return false;
}
// TC - o(n logn)
// SC - O(n) 

// using two pointer
bool twoSum4(int arr[], int n, int k) {
    int start = 0, end = n-1;
    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum < k) start++;
        else if (sum > k) end--;
        else return true;
    }
    return false;
}


int main() {


    return 0;
}
