#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

//------------ Find the Smallest Divisor Given a Threshold -------
bool getDivisons(vector<int> &arr, int divisor, int limit) {
    int divisons = 0;
    for (int i=0; i<arr.size(); i++) {
        divisons += (arr[i] + divisor - 1) / divisor; // ceil value       
        // divisons += (arr[i] - 1) / divisor + 1; // fast ceil calc

        if (divisons > limit) return false;
    }
    return true;
}

int smallestDivisor(vector<int> &arr, int limit) {
    int low = 1;
    int high=*max_element(arr.begin(), arr.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (getDivisons(arr, mid, limit)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
// TC - O(log(max(arr)) x N)

int main() {
    vector<int> arr = {1,2,3,4,5};
    int limit = 8;

    cout << smallestDivisor(arr, limit);

    return 0;
}
