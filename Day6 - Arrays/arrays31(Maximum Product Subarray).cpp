#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

// =========== Maximum Product Subarray in an Array =================
// problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

int productSubarray(vector<int> arr) {
    int n = arr.size();
    long long maxPro = 0;
    for (int i=0; i<n; i++) {
        long long subPro = 1;
        for (int j=i; j<n; j++) {
            subPro *= arr[j];
            maxPro = max(maxPro,subPro);
        }
    }
    return maxPro;
}


// --- optimal 
// using prefix and sufix - intiutive
productSubarray3(vector<int> arr) {
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    int n = arr.size();

    for (int i=0; i<n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;

        pre *= arr[i];
        suff *= arr[n-1 -i];
        ans = max(ans, max(pre, suff));
    }
}
// TC - O(n) 
// Sc - O(1)



// using kadanes algo
int productSubarray2(vector<int> arr) {
    int n = arr.size();
    long long maxPro = arr[0];
    long long minPro = arr[0];
    long long ans = arr[0];

    for (int i=1; i<n; i++) {
        if (arr[i] < 0) swap(maxPro, minPro);

        maxPro = max((long long)arr[i], maxPro * arr[i]);
        minPro = min((long long)arr[i], minPro * arr[i]);
        ans = max(maxPro, ans);
    }
    return ans;
}
// TC - O(n) 
// SC - O(1) 



int main() {
    vector<int> arr  = {1,2,-3,0,-4,-5};
    cout << productSubarray2(arr);


    return 0;
}
