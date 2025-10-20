#include <iostream>
#include <vector> 
#include <climits>


using namespace std;

// ------------- Capacity to Ship Packages within D Days ----------

bool getDays(vector<int> &arr, int weight, int dayLimit) {
    int weights = 0;
    int days = 1;
    for (int i=0; i<arr.size(); i++) {
        if (weights + arr[i] > weight) {
            days++;
            weights = 0;
        }
        weights += arr[i];

        if (days > dayLimit) return false;
    }
    return true;
}

int shipPackage(vector<int> &arr, int dayLimit) {
    // int low = 1;
    // int high = accumulate(arr.begin(), arr.end(), 0);
    int low=INT_MAX, high=0;
    for (int it:arr) {
        low = min(low, it);
        high += it;
    }

    // edge case
    if (dayLimit == 1) return high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (getDays(arr, mid, dayLimit)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
// TC - O(log(max(arr) - min(arr)) x n)



int main() {
    vector<int> arr = {5,4,5,2,3,4,5,6} ;
    int dayLimit = 5;

    cout << shipPackage(arr, dayLimit) << endl;

    return 0;
}
