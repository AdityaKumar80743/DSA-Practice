#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

// print set till n
void printS(set<int> &mset) {
    for (auto it:mset) cout << it << " ";
    cout << endl;
}

// print vector till n
void print(vector<int> &arr, int n) {
    for (auto i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

// print map till n
void printM(map<int,int> &mpp) {
    for (auto it:mpp) cout << it.first << " ";
    cout << endl;
}


// ------------ LINEAR SEARCH ----------------
// find the index where the target number appears first
// iterate through the whole ray in linear manner (one by one till the end is reached)
int linearSearch(int arr[], int n, int target) {
    for (int i=0; i<n; i++) {
        if (arr[i] == target) return i; // target found 
    }
    return -1; // target not found
}
// TC - O(n)



// ------------- UNION OF TWO ARRAYS ----------------
// problem: two array which are sorted, can have duplicates 
// find union to the two array (union do not have duplicates and it is should be sorted)

// using set - as set store only unique elements
void unionArr(int arr1[], int arr2[], int n1, int n2) {
    set<int> distinct;

    for (int i=0; i<n1; i++) {
        distinct.insert(arr1[i]);
    } 
    for (int i=0; i<n2; i++) {
        distinct.insert(arr2[i]);
    }
    printS(distinct);
}
// TC - O(n1 + n2 + nlogn(insertion)) 
// SC - O(n1 + n2)


// using map
void unionArr2(vector<int> arr1, vector<int> arr2) {
    map<int, int> mpp;
    
    for (int i=0; i<arr1.size(); i++) {
        mpp[arr1[i]]++; // logn
    }
    for (int i=0; i<arr2.size(); i++) {
        mpp[arr2[i]]++; // logn
    }
    printM(mpp);
} 
// TC - O(logn + logn) 


// --- optimal way 
// using pointers

// STEPS:
// take two pointer for both arrays and create a result vector 
// pick smallest amoung the arrays
// if not equal to the last elem of result vector - add to result vector
// when one of the arrays gets exhausted add the elements of other array
// - alwasy check result vector last element before adding

// TC - O(n1 + n2) 
// Sc - O(N1+ N2)
void unionArr3(vector<int> a1, vector<int> a2) {
    vector<int> uniArr;
    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0;
    int j = 0;
    
    while (i<n1 && j<n2) { // until pointer are smaller then the arrays size
        if (a1[i] <= a2[j]) { // pick smallest among a1[i] and a2[j]
            if (uniArr.size() == 0 || uniArr.back() != a1[i]) { // if last elem in uniArr not equal to smallest then push smallest else move pointer
                uniArr.push_back(a1[i]);
            } i++;
        }
        else if (a1[i] > a2[j]) {
            if (uniArr.size() == 0 || uniArr.back() != a2[j]) {
                uniArr.push_back(a2[j]);
            } j++;
        }
    }
    
    // IF one of the array is exhausted 
    while (j<n2) {
        if (uniArr.size() == 0 || uniArr.back() != a2[j]) {
                uniArr.push_back(a2[j]);
            } j++;
    }
    
    while (i<n1) {
        if (uniArr.size() == 0 || uniArr.back() != a1[i]) {
                uniArr.push_back(a1[i]);
            } i++;
    }
    
    print(uniArr, uniArr.size());
}


// --------------- INTERSECTION OF TWO ARRAYS -------------

// --- burute force approach
// using set 
void intersection(vector<int> ao, vector<int> at) {
    set<int> intersect;
    
    for (int i=0; i<ao.size(); i++) {
        for (int j=0; j<at.size(); j++) {
            if (ao[i] == at[j]) intersect.insert(ao[i]);
        }
    }
    printS(intersect);
}
// TC - O(n^2)
// SC - O(n)

// --- optimal 
// similar to union - slight logical change
void intersection(int a1[], int a2[], int n1, int n2) {
    int i = 0;
    int j = 0;
    vector<int> res;

    while (i<n1 && j<n2) {
        if (a1[i] < a2[j]) i++;
        else if (a2[j] < a1[i]) j++;
        else {
            res.push_back(a1[i]);
            i++;
            j++;
        }    
    }
    print(res, res.size());
}
//TC - O(n1 + n2)
// SC - O(n1 + n2)


int main() {
    int arr1[5] = {1,2,3,4,5};
    int arr2[3] = {1,2,6};

    intersection(arr1, arr2, 5,3);


    return 0;
}
