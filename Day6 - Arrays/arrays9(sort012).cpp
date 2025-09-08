#include <iostream>
#include <algorithm>

using namespace std;

// print an array 
void print(int arr[], int n) {
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

// ------------ sort an array of 0's, 1's and 2's ----------

// --- brute force
// using sorting algorithms or stl sort
void sortArr(int arr[], int n) {
    sort(arr, arr+n);
}
// when using merge sort 
// TC - O(nlogn) 
// SC - 0(n)

// better approch 
// using counting variables
void sortArr2(int arr[], int n) {
    // initially the counters to track frequency
    int count0 = 0, count1 = 0, count2 = 0;
    
    // loop to the array and updating counters - TC-O(n)
    for (int i=0; i<n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else count2++;
    }
    
    // total TC - O(n) 
    for (int i=0; i<count0; i++) arr[i] = 0; // 0 to no. of 0's
    for (int i=count0; i<count0+count1; i++) arr[i] = 1;
    // no. of 0's to no. of 1's
    for (int i=count0+count1; i<n; i++) arr[i] = 2;
    // no. of 1's to n ;
}
// TC - O(n + n) 
// SC - O(1)


// --- optimal 
// --- DUTCH NATIONAL FLAG ALGORITHM ---

// using 3 pointers 
// 0 - low-1 (all 0's)
// low - mid-1 (all 1's)
// mid - high-1 (unsorted part)
// high - n-1 (all 2's)

// 0    low     mid    high    n-1
// 000000|1111111|120120|2222222

void sortArr3(int arr[], int n) {
    int low= 0, mid= 0, high= n-1;
    
    while (mid < high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) mid++;
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
// TC - O(n) 
// SC - O(1)

int main() {
    int n = 8;
    int arr[n] = {2,2,1,1,0,1,0,0};
    
    cout << "original " << print(arr, n);
    sortArr3(arr, n);
    cout << "sorted " << print(arr, n);
    
    return 0;
}
