//  binary search is applicable on sorted array's
//  it reduce's the search space half with each step

#include <iostream>
#include <vector>

using namespace std;

// binary search Algorithm

// iterative implementation
int binarySearch(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // target found
        if (arr[mid] == target) return mid;
        // remove right portion from the mid
        else if (arr[mid] < target) high = mid - 1;
        // remove left portion from the mid
        else low = mid + 1;
    }
    return -1; // not found
}

// recursive implementation
int binarySearchR(vector<int> arr, int target, int low, int high) {
    if (low > high) return -1; // target not found

    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid; // target found
    // trim left half
    else if (arr[mid] > target) binarySearchR(arr, target, mid+1, high);
    // trim right half
    else binarySearchR(arr, target, low, mid-1);
}

// Tc - O(logn) with base 2 

// tip better write - low - (high - low) / 2 
// prevent overflow

int main() {
    vector<int> arr = {1,2,3,4,5,6,7}
    int target = 6;

    cout << binarySearch(arr, target) << endl;
    cout << binarySearchR(arr, target, 0, arr.size()-1) << endl;

}
