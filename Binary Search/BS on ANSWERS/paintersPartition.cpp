#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

// --------------- Painter's Partition Problem ------------

bool partitionPossible(vector<int> &arr, int maxPainters, int hours) {
    int painters = 1;
    long long boards = 0;

    for (int i=0; i<arr.size(); i++) {
        if (boards + arr[i] <= hours) boards += arr[i];
        else {
            painters++;
            boards = arr[i];
        }
        if (painters > maxPainters) return false;
    }
    return true;
}

int paintersPartition(vector<int> &arr, int maxPainters) {
    int low=INT_MIN, high=0;

    // find max and sum
    for (int i=0; i<arr.size(); i++) {
        low = min(low, arr[i]);
        high += arr[i];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (partitionPossible(arr, maxPainters, mid)) high = mid - 1; 
        else low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> arr = {5, 5, 5, 5};
    int k = 2;

    cout << paintersPartition(arr, k);

    return 0;
}
