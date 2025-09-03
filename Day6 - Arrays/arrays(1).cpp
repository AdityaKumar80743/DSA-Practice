#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


// 1. ---------- LARGEST ELEMENT ----------

// ---- Brute force - using sort
// last element will be the largest 
int largestElem(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n-1];
}
// TC - O(nlogn) 
// SC - O(1)


//--- optimal 
int largestElem2(int arr[], int n) { 
    // handle edge cases   
    if (n < 1) return -1; // array is empty
    if (n == 1) return arr[0]; // if only one element present - that is the largest element

    int largest = arr[0]; // store the largst element - at start first element is largest
    for (int i=1; i<n; i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // new largest element found
        }
    }
    return largest;
}
// TC - O(n) 
// SC - O(1)




// 2. ----------- SECOND LARGEST ELEMENT ----------
// in a unsorted array

// --- Brute force 
// sort the array and the second largest element [n-2]
int secondLargestElem(int arr[], int n) {
    sort(arr, arr + n); // TC - nlogn
    int largest = arr[n-1];

    // iterate from the last and check if the element if not equal to largest - if so it is the second largest
    // this works even if array has multiple repeating of largest element 
    for (int i=n-2; i>=0; i--) { // worst case - O(n)
        if (arr[i] != largest) {
            return arr[i];
        }
    }
    return -1;
}
// TC - O(nlogn + n) 
// SC - O(1)

// --- better approach
// using two loops - one to find largest and other for second largest 
int secondLargestElem2(int arr[], int n) {
    int largest = arr[0];
    int second = -1;
    
    // find the largest elment
    for (int i=1; i<n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // find second largest elment
    for (int i=0; i<n; i++) {
        // check if current element if greater then second and less than largest element
        if (arr[i] > second && arr[i] < largest) {
            second = arr[i];
        }
    }
    return second;
 }
// TC - O(n - n)
// SC - (1)  


// --- optimal arroach
int secondLargestElem3(int arr[], int n) {
    // can handle edge cases like empty array
    // single element array

    int first = arr[0];
    int second = -1; 
    // if array contain negative num use - INT_MIN

    for (int i=1; i<n; i++) {
        if (arr[i] > first) {
            second = first; // first largest elemnet becomes second largest element
            first = arr[i]; // update first largest element
        } else if (arr[i] < first && arr[i] > second) { // if arr[i] is < first largest but arrr[i] > second - update second
            second = arr[i]; // update second
        }
    }
    return second;
}
// TC - O(n)
// SC - O(1)



//3. ------------------ CHECK IF SORTED ---------------
bool checkSorted(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        // current element should be smaller than next elemnet for accending sort
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}


// 4. -------------- REMOVE DUPLICATES -------------
// print all the unique element in the SORTED array

// function to print elements in a set
void printSet(set<int> arr) {
    for (auto it:arr) cout << it << " ";
}

// fuction to print elements in a vector till n
void print(vector<int> arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

// function to print elements of array til n
void printArray(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

// --- Brute force
// using set (only contains unique values)
void removeDuplicates(int arr[], int n) {
    set<int> uniques;

    for (int i=0; i<n; i++) {
        uniques.insert(arr[i]);
    }
    printSet(uniques); 
    // if want to return the result change the function type to set<int>
}
// TC - O(n) to solve the problem - addtional to print the result 
// set insertion takes - O(logn)
// SC - O(A) - A (all unique elements) to store in a set
// but for worst case - O(N) - all element are unique

// --- Better
// using array
void removeDuplicates2(int arr[], int n) {
    vector<int> uniques = {arr[0]};

    for (int i=1; i<n; i++) {
        if (arr[i] != arr[i-1]) {
            uniques.emplace_back(arr[i]);
        }
    }
    print(uniques, uniques.size());
} 
// TC - O(n) - for solving
// SC - O(n)

// --- optimal
// using pointers
// we can use pointers to point on postion where the uniqure elements can be and swap it with repeating elements
void removeDuplicates3(int arr[], int n) {
    int pointer = 0; 
    // this pointer store the postion where the next unique elements should be..

    for (int i=0; i<n; i++) {
        if (arr[i] != arr[i+1]) { // if the current element is not same as next then it is a unique element
            swap(arr[i], arr[pointer]); // swap the uniuqe element to put it in it's correct postion
            pointer++; // update the pointer - shift the position
        }
    }
    printArray(arr, pointer);
}


int main() {
    int arr[10] = {1,2,2,3,4,5,5,5,5,6};

    // cout << secondLargestElem(arr, 5) << endl;    
    removeDuplicates3(arr, 10);
    return 0;
}
