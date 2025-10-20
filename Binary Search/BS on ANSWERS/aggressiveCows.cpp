#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

// ------------ Aggressive Cow ------------

bool canWePlace(vector<int> stalls, int cows, int dist) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];

    for (int i=1; i<n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
} 

int aggressiveCows(vector<int> &stalls, int cows) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canWePlace(stalls, cows, mid)) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
// TC - O(log(min(arr) - max(arr)) x n) + (nlogn) - sorting


int main() {
    vector<int> arr = {0,3,4,7,10,9};
    int cows = 4;

    cout << aggressiveCows(arr, cows) << endl;


    return 0;
}
