#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

// koko eating banana

// --- brute force
int koko(vector<int> arr, int h) {
    int n = arr.size();
    int i = 1;

    while (true) {
        int hours = 0;
        for (int j=0; j<n; j++) {
            if (arr[j] % i == 0) hours += arr[j] / i;
            else hours += (arr[j] / i) + 1;
        }
        if (hours <= h) return i;
        i++;
    }
    return -1;
}
// TC - (max(arr) x n) 



// --- optimal 
int hours(vector<int>& arr, int speed) {
    int hour = 0;
    for (int i = 0; i < arr.size(); i++) {
        hour += (arr[i] + speed - 1) / speed;  // ceil(arr[i] / speed)
    }
    return hour;
}

int koko2(vector<int>& arr, int h) {
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int totalHours = hours(arr, mid);

        if (totalHours <= h) {
            ans = mid;      // store the speed, not totalHours
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
// TC - O(log(max(arr)) x n) 

int main() {
    vector<int> arr =  {7, 15, 6, 3};
    int h = 8;
    cout << koko2(arr, h);


    return 0;
}
