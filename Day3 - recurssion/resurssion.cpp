#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// when there is infinite recurssion all the previous funtion will wait in the memory - making a stack - and when the memory if full - stack overflow is caused;

// so must have Base conditon (stopping conditoin)

// ----------------------------------------------------------

// print name n times
void printName(int n) {
    if (n <= 0) return;
    cout << "aditya" << " ";
    printName(n-1);
} // Tc - O(n) ; sp O(n) as stack memory

// 1 to n linear print
void printLinear(int n, int cn = 1) {
    cout << cn << " ";
    if (cn == n) return;
    printLinear(n, cn+1);
}

// n to 1 linar print
void printLinearn(int n) {
    if (n <= 0) return;
    cout << n << " ";
    printLinearn(n-1);
}

// Back tracing 1 to n
void back1ToN(int n , int i) {
    if (i < 1) return;
    back1ToN(n, i-1);
    cout << i << " ";
}

// In back traking the first function watis for other stack function  and then do the rest thing written

// Back tracking n to 1
void backNto1(int n, int i = 1) {
    if (i > n) return;
    backNto1(n, i+1);
    cout << i << " ";
}

// #---------------------------------------
// Sum of n numbers
// parameter method
int summ(int n, int sum=0) {
    if (n < 1) return sum;
    return summ(n-1, sum+n);
}

// functional method
int summ2(int n) {
    if (n < 1) return 0;
    return n + summ2(n-1);
}

// factorial of n (n!)
int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

// print vector

// Reverse an array
// 2 pinter
void reverseArray(vector<int> v, int left, int right) {
    if (left >= right) return;
    v.swap(v[left], v[right]);
    reverseArray(v,left+1, right-1);
}

// 2
// 1 pointer
void reverseArray2(vector<int> v, int i = 0) {
    if (i == v.size() / 2) return;
    v.swap(v[i], v[v.size()-1-i]);
    reverseArray2(v, i+1)
}

// check string palindrome
bool palindrome(string st) {
    cout << " yes";
} // same as above 2 

// fabinaci numbers
int fabonaci(int n, int a = 0, int b = 1, int count = 1) {
    if (count == n) return b;
    return fabonaci(b, a+b);
}

// 2 - much better 
int fabonaci2(int n) {
    if (n <= 1) return n;
    return fabonaci2(n-1) + fabonaci2(n-2);
} 
// it has tc - O(2^n) - exponential - iterative method is much better


// every fuction defined above can be called inside main() with proper arguments
// below is example of calling palindrome

int main() {
    // vector<int> v = {1,2,3,4,5};
    string st = "madam";
    bool total = palindrome(st);
    cout << total << endl;


    return 0;
}
