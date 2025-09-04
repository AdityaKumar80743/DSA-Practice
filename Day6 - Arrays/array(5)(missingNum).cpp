#include <iostream>

using namespace std;

//---------------- MISSING NUMBER ----------
// PROBLEM: given a array of size n-1
// having number from 1 to n
// one number is missing find it out

// as the numbers in the array always starts from 1 and goes till n 
// each elemnt should be equal to their respective index in the array plus one (i+1)
// works only if array is SORTED..
int missingNum(int arr[], int n) {
   for (int i=0; i<n; i++) {
       if (arr[i] != i+1) return i+1;
   }
   return -1;
}
// similarly can do - arr[i] - arr[i+1] != 1;
// if differene of current and next element is not 1 then missing element found

// TC - O(n)
// SC - O(1)

// --- better
// using hashing
int missingNum2(int arr[], int n) {
    int mapp[n+1] = {0}; // at start frequency fo all numbers is zero
    
    for (int i=0; i<n; i++) mapp[arr[i]]++; // update the frequency of the element on their respective index
        
    // check in hash map where frequency if zero - the the missing number
    for (int i=1; i<n+1; i++) {
        if (mapp[i] == 0) return i;
    }
    return -1; // not found
}
// Tc - O(n) 
// SC - O(n)


// --- optimal
// as the array has one missing element from 1 to n
// take the actual sum of the array and subtract with formula sum 
// as formula sum will have all the elements from 1 to n - subtraction will give the missing element (reverse thinking) 
// work for unsortred array 
int missingNum3(int arr[], int n) {
    long long sum = 0; // use long for larger values
    for (int i=0; i<n; i++) sum += arr[i];
    
    // n++; as actula array has n-1 size
    long long formulaSum = (n+1) * (n/2);
    return formulaSum - sum;
}
// TC - O(n)
// SC - O(1)

// --- optimal --- XOR method ---
// a xor a = 0
// a xor 0 = a;
// convert the number into binary form and apply above property to get the xor 
// ex. 5 xor 7 = 2 

// so use two xor 
// in xor 1 add all values from 1 to n
// in xor 2 add values in the array
// now xor them both with each other 
// result will the be missing number

int missingNum4(int arr[], int n) {
    int xor1 = 0; // for 1 to n
    int xor2 = 0; // for elements in array
    
    for (int i=1; i<=n+1; i++) {
        xor1 ^= i; // xor 1 to n
        xor2 ^= arr[i-1]; // as index start form 0 till n-1
    }
    return xor1 ^ xor2; // missing element
}
// TC - O(N) 
// SC - O(1)
// but better than missingNum3 as xor use bits

int main() {
    int arr[5] = {1,2,5,4,6};
    cout << missingNum4(arr, 5);
    
    
    return 0;
}
