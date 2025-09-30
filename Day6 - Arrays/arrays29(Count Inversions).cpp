#include <iostream>
#include <vector>

using namespace std;

//=================== Count inversions in an array =============

// --- brute 
int inversion(vector<int> arr) {
    int n = arr.size();
    int count = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[i]) count++;
        }
    }
    return count;
}
// TC - O(n x n) 
// SC - O(1)



//  -- - optimal 

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int cnt = 0;

    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
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
    cnt += merge(arr, low, mid, high);
    return cnt;
}
// TC - O(n logn) 
// SC - O(n) 




int main() {
    vector<int> arr =  {5,4,3,2,1};
    cout << mergeSort(arr,0,arr.size()-1);


    return 0;
}
