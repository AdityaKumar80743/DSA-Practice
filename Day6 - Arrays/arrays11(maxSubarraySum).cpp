#include <iostream>
#include <climits> // for using INT_MIN

using namespace std;

// =========== MAXIMUM SUBARRAY SUM =============
// PROBLEM: find the subarray which has the maximum sum of their respective elements
// VARIATIONS; 1. give the max sum
//           2. give the subarray starting and ending indexes 

// --- brute force
// find the sum of all the subarrays possible and store the maximum sum found
int maxSum(int arr[], int n) {
    int maxs = INT_MIN;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += arr[j];
            maxs = max(maxs, sum);
        }
    }
    return maxs;
}
// TC - O(n^2) 
// SC - O(1)


// --- optimal 
// =============== KADANE'S ALGORITHM =============

int maxSum2(int arr[], int n) {
    int maxs = INT_MIN;
    
    int sum = 0;
    int start; // for index of start and end of subarray
    int end;
    
    for (int i=0; i<n; i++) {
        if (sum == 0) start = i; // if sum = 0 start new subarray
        sum += arr[i];
        if (sum > maxs) {
            end = i; // found new max end the subarray
            maxs = sum;
        }
        else if (sum < 0) { // dont use <= as it reduces the subarray ex. [1,-1,1] and [1] both have same sub but 1st one is larger 
            sum = 0;
        }
    }
    return max(maxs, 0); // include empty set - which has sum of 0 - if masx is -ve return null set sum;
    // or return the indexes of the subarray
}
// TC - O(n) 
// SC - O(1)



int main() {
    int n = 5;
    int arr[n] = {1,2,5,-1,6};
    
    cout << maxSum2(arr, n);
    

    return 0;
}
