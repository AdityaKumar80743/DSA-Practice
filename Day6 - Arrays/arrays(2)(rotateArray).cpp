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

// ------------ LEFT ROATATE ARRAY BY ONE PLACE------------
// shifting
void rotateArray(int arr[], int n) {
    int temp = arr[0]; // store fist element 

    for (int i=0; i<n-1; i++) {
        arr[i] = arr[i+1]; // shift the element to the left by one position
    }
    arr[n-1] = temp; // place the first element at the last
    print(arr, n);
}
// to solve the above problem we are using O(1) space 
// - but for solving the problem whole we are taking O(N) space -- size of the arr   
// Always specify the SC in space taken to solve the problem
// not space taken to return or dispaly the result



// --------------- LEFT ROTATE THE ARRAY TO D PLACES ----------   

// --- brute force use left rotate by one position n times
void leftRotateD(int arr[], int n, int d) {
    d %= n; // avoid extra roations of array 
    // if d > n then d restart from 1
    // d will not be greater than n 

    for (int i=0; i<d; i++) {
        rotateArray(arr, n);
    }
}
// TC - O(n^2)
// SC - O(1)

// --- better
// using another array
void leftRotateD2(int arr[], int n, int d) {
    d %= n; // optimisation d will not be > n
    vector<int> res; // stores the result 

    // place the elemetns from D at the start in order
    for (int i=d; i<n; i++) {
        res.emplace_back(arr[i]); 
    }
    // place the elements from 0 to d after d  postion
    for (int i=0; i<d; i++) {
        res.emplace_back(arr[i]);
    }
    printM(res, n);
}
// TC - O(n)
// SC - O(n)

// --- optimal
// divide the array in two halves 
// 1st 0 to d
// 2nd d+1 to n
// reverse both halves and then reverse the whole array

// for reverse use STL or make reverse function

// reverse 
void reverse1(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void leftRotateD3(int arr[], int n, int d) {
    d %= n; // handle overlfow of d 
    reverse(arr, arr + d); // reverse left half
    reverse(arr + d, arr + n); // revere right half
    reverse(arr, arr + n); // reverse whole array
    print(arr, n);
}
// TC - O(2n) 
// SC - O(1)

int main() {
    int arr[5] = {1,2,3,4,5};

    leftRotateD3(arr, 5, 8);


    return 0;
}
