#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// =============== COUNT SUBARRAY SUM EQUALS K ===============

/* Problem Statement: Given an array of integers
 and an integer k, return the total number of subarrays whose sum equals k.
*/ 


// --- brute force
int subarray(vector<int> arr, int target) {
    int n = arr.size(); 
    int count = 0;

    for (int i=0; i<n; i++) {
        int subSum = 0;
        for (int j=i; j<n; j++) {
            subSum += arr[j];
            if (subSum == target) {
                count++;
            }        
        }
    }
    return count;
}
// TC - O(n*n) 
// SC - O(n)


// this work only for positive elements
int subarray2(vector<int> arr, int target) {
    int n = arr.size();
    int left = 0, right = 0;
    int sum = arr[0], count = 0;

    while (right < n) {
        if (sum < target) {
            right++;
            sum += arr[right];
        }
        else if (sum > target) {
            sum -= arr[left];
            left++;
        }
        else {
            count++;
            right++;
            sum += arr[right];
        }
    } 

    return count;
}
// TC - O(2n)
// SC - O(1)

// --- optimal
// similar to problem; subarray with max sum
// concept of presum
int subarray3(vector<int> arr, int k) {
    unordered_map<int, int> mapp;
    mapp[0] = 1;

    int preSum = 0, count = 0;

    for (int i=0; i<arr.size(); i++) {
        preSum += arr[i];
        int remove = preSum - k;
        count += mapp[remove];
        mapp[preSum] += 1;
    }
    return count;
}
// TC - O(n) - depends on which type of map you use - if map - then O(n x logn)
// SC - O(1)


int main() {
    vector<int> arr  = {1,2,3,6,-3};
    int target = 3;

    cout << subarray(arr, target);

    
    return 0;
}
