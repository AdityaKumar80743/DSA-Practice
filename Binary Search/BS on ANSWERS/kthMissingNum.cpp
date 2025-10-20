#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

 // --------------------- Kth Missing Positive Number ---------

// --- brute force
int kthMissing(vector<int> &arr, int k) {
    int n = arr.size();
    int start = 1;
    int count = 0;

    for (int i=0; i<n; i++ ) {
        for (int j=start; j<=arr[i]; j++) {
            if (j != arr[i]) count++;
            if (count == k) return j;
        }
        start = arr[i]+1;
    }
    return -1;
}
// TC - O(n x max(arr)) 


// --- better 1
int kthMissing2(vector<int> &arr, int k) {
    int i=0;
    int high = *max_element(arr.begin(), arr.end());
    int count = 0;

    for (int j=1; j<high; j++) {
        if (arr[i] == j) {
            i++;
            continue;
        } 
        count++;
        if (count == k) return j;
    }
    return -1;
}
// TC - O(max(arr)) 


// --- better 2
int kthMissing3(vector<int> &arr, int k) {
    int n = arr.size();
    for (int i=0; i<n; i++) {
        if (arr[i] <= k) k++;
        else break;
    }
    return k;
}


// --- optimal
int kthMissing4(vector<int> &arr, int k) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] - (mid + 1) < k) low = mid + 1;
        else high = mid - 1;
    }
    return k + high + 1;
}

int main() {
    vector<int> arr = {4,7,9,10};
    int k = 6;

    cout << kthMissing3(arr, k);

    return 0;
}
