#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ============== Count the number of subarrays with given xor K ================ 

// --- brute 
// generate all subarray and find xor of each subarray
int subToK(vector<int> arr, int target) {
    int n = arr.size();
    int count = 0;
    for (int i=0; i<n; i++) {
        int ans = 0;
        for (int j=i; j<n; j++) {
            ans ^= arr[j];
            if (ans == target) count++;
        }
    }
    return count;
}
// TC - O(n x n) 
// SC - O(1)

// --- optimal
// same logic as subarray sum and multiplication
int subToK2(vector<int> arr, int target) {
    int n = arr.size();
    map<int, int> hash;
    hash[0] = 1;

    int count = 0;
    int totalXor = 0;
    for (int i=0; i<n; i++) {
        totalXor ^= arr[i];
        int x = target ^ totalXor;
        count += hash[x];
        hash[x] += 1;
    }   
    return count;
}
// TC - O(n) 
// SC - O(n) 

int main() {
    vector<int> arr  = {4,2,2,6,4};
    int target = 6;
    cout << subToK2(arr,target) << endl;


    return 0;
}
