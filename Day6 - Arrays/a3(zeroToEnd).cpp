#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// print array till n
void print(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

// print vector till n
void printM(vector<int> &arr, int n) {
    for (auto i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}


// ----------------  MOVE ALL ZERO'S TO END ------------

// brute force -
// sort and reverse

void zeroToEnd0(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end()); // TC - nlogn
    reverse(arr.begin(), arr.end()); // O(N)
    print(arr, n);
}

// --- better
// using another array 
// pick all the non zero num and store in temp arr then all remaining place - fill with zero
void zeroToEnd(int arr[], int n) {
    int res[n]; // store result
    int p = 0; // postion where the non zero element should be

    for (int i=0; i<n; i++) {
        if (arr[i] != 0) { // add non zero element to result array
            res[p] = arr[i];
            p++;
        }
    }

    // now all remaing postin in result array should be zero's
    for (int i=p; i<n; i++) {
        res[i] = 0;
    }
    print(res, n);
}
// TC - O(n + n-p)
// SC - O(n)


// --- optimal
// using pointers 
// when non zero element found swap if with zeroIdx
void zeroToEnd2(int arr[], int n) {
    int zeroIdx = 0;
    
    for (int i=0; i<n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[zeroIdx]);
            zeroIdx++;
        }
    }
    print(arr,n);
}
// TC - O(n) 
// SC - O(1)

int main() {
    int arr[5] = {1,0,3,0,5};
    zeroToEnd2(arr, 5);

    return 0;
}
