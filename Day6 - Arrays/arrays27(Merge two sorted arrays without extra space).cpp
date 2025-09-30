#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void prints(vector<int> arr) {
    for (int it:arr) cout << it << " ";
    cout << endl;
}

//================= Merge two Sorted Arrays Without Extra Space ==========

void func(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    long long res[n+m];

    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            res[index] = arr1[left];
            left++, index++;
        }
        else {
            res[index] = arr2[right];
            right++, index++;
        }
    }

    while (left < n) {
        res[index++] = arr1[left++];
    }

    while (right < m) {
        res[index++] = arr2[right++];
    }

    for (int i=0; i<n+m; i++) {
        if (i<n) arr1[i] = res[i];
        else arr2[i-n]  = res[i];
    }
}
// TC - O(2 (n+m))
// SC - O(n+m)


// optimal
void func2(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    int left = n -1;
    int right = 0;

    while (left >=0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            right++, left--;
        }
        else break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
// TC - O(min(n,m) + nlogn + mlogm)
// SC  - O(1)


// optimal 
void swapIfGreater(long long &arr1[], long long &arr2[], int idx1, int idx2) {
    if (arr1[idx1] > arr2[idx2]) {
        swap(arr1[idx1], arr2[idx2]);
    }
}

void func3(long long &arr1[], long long &arr2[], int n, int m) {
    int len = (n+m);
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // arr1 and arr2
            if (left < n && right >= n) {
                swapIfGreater(arr1,arr2, left, right - n);
            }
            // arr2 and arr2
            else if (left >=n) {
                swapIfGreater(arr2,arr2, left -n, right -n);
            }
            // arr1 and arr1
            else {
                swapIfGreater(arr1,arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1) break;
        gap = (gap/ 2) + (gap % 2);
    }
}
// TC - O(log(m+m) x (n+m))
// SC - O(n)

int main() {
    long long arr1 = {1,4,7,8};
    long long arr2 = {3,5,6};
    int n = arr1.size(); 
    int m = arr2.size();

    func3(arr1,arr2,n,m);

    prints(arr1);
    prints(arr2);

    return 0;
}
