#include <iostream>
#include <map>

using namespace std;

// ----------- MAJORITY ELEMENT --------------

// --- brute force 
int majority(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=i; j<n; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > n/2) return arr[i];
    }
    return -1;
}
// TC - O(n^2)
// SC - O(1)


// --- better 
// using hashing
int majority2(int arr[], int n) {
    map<int, int> hash;
    
    for (int i=0; i<n; i++) { // track each element frequency
        hash[arr[i]]++;
    }
    for (auto it:hash) { // check is majority (> n/2)
        if (it.second > n/2) return it.first;
    }
    return -1; // no majority element
}
// TC - (n + n) 
// SC - O(n)


// --- optimal
// ============ MOORE'S VOTING ALGORITHM ============

// as lmajority element is > n/2 - it can cancell all other elements
int majority3(int arr[], int n) {
    int flag = 0;
    int elem;
    
    for (int i=0; i<n; i++) {
        if (flag == 0) {
            elem = arr[i];
            flag++;
        }
        else if (arr[i] == elem) flag++;
        else flag--;
    }
    // confirm if the element is majority
    int count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == elem) count++;
    }
    if (count > n/2) return elem;
    else return -1; // not found
}
// TC - O(n+n) 
// SC - O(1)

int main() {
    int n = 10;
    int arr[n] = {1,1,1,2,1,2,2,2,1,2};

    cout << majority3(arr, n);

    return 0;
}
