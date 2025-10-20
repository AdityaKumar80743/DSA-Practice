#include <iostream>
#include <vector> 
#include <algorithm>
#include <climits>

using namespace std;

int getPairs(vector<int> &arr, int n , int days) {
    int pairs = 0;
    int count = 0;

    for (int i=0; i<arr.size(); i++) {
        int ceil = days / arr[i];

        if (ceil > 0) count++;
        else count = 0;

        if (count == n) {
            pairs++;
            count = 0;
        }
    }
    return pairs;
}

int bouquets(vector<int> &arr, int m, int n) {
    // edge case
    if (arr.size() < (m*n)) return -1;

    int low = INT_MAX, high = INT_MIN;
    // make a seperate function to caluculate low and high in O(n)
    for (int it:arr) {
        low = min(low, it);
        high = max(high, it);
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int pairs = getPairs(arr, n, mid);

        if (pairs >= m) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}
// TC - O(log(max(arr) - min(arr)) x n)

int main() {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2;
    int n = 3;
    cout << bouquets(arr, m, n) << endl;

    return 0;
}
