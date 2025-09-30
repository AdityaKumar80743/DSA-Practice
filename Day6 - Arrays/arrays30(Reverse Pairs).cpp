#include <iostream>
#include <vector> 

using namespace std;

// =============== Count Reverse Pairs ===================
// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].


// --- brute force
int reversePair(vector<int> arr) {
    int n = arr.size();
    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (arr[i] > (2 * arr[j])) count++;
        }
    }
    return count;
}
// TC - O(n x n) 
// SC - O(1)





// --- optimal 
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}

int countPairs(vector<int> arr, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;
    for (int i= low; i<= mid; i++) {
        while(right <= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    // base case 
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}
// TC - O(2nlogn) 
// SC - O(n) 


int main() {
    vector<int> arr = {1,3,2,3,1};
    cout << mergeSort(arr,0, arr.size()-1);


    return 0;
}
