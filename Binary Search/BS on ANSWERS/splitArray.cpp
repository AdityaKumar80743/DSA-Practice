#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

// ---------- Split Array - Largest Sum ----------

bool splitPossible(vector<int> &arr, int k , int sum) {
    int n = arr.size();
    int splits = 1;
    long long sSum = 0;

    for (int i=0; i<n; i++) {
        if (sSum + arr[i] <= sum) {
            sSum += arr[i];
        }
        else {
            splits++;
            sSum = arr[i];
        }
        if (splits > k) return true;
    }
    return false;
}

int splitArray(vector<int> &arr, int k) {
    int low=INT_MIN, high=0;

    // find max and sum of arr
    for (int i=0; i<arr.size(); i++) {
        low = max(low, arr[i]);
        high += arr[i];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (splitPossible(arr,k,mid)) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    vector<int> arr =  {1,2,3,5,4};
    int k = 3;

    cout << splitArray(arr, k);

    return 0;
}
