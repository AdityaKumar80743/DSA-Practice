#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// print vector
void print(vector<int> arr) {
    for (int it:arr) cout << it << " ";
    cout << endl;
}

// ================== Find the repeating and missing numbers ==============
// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N]
//  both inclusive. Each integer appears exactly once except A which appears twice and B which is missing.
//   The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.


// better than brute
vector<int> missingRepeating(vector<int> arr) {
    int n = arr.size();
    vector<int> res(2,-1);
    sort(arr.begin(), arr.end()); // sort

    for (int i=0; i<n-1; i++) {
        // repeating
        if (arr[i] == arr[i+1]) res[0] = arr[i];
        // missing
        if (arr[i+1] - arr[i] > 1) res[1] = arr[i]+1;
    }
    if (res[1] == -1) res[1] = n;
    return res;
}
// TC - O(nlogn + n)
// SC - O(1)


// better
vector<int> missingRepeating2(vector<int> arr) {
    int n = arr.size();
    vector<int> hash(n+1,0); // hashmap
    vector<int> res(2,-1);

    for (int i=0; i<n; i++) {
        hash[arr[i]] += 1; // upate frequency
    }

    for (int i=1; i<n+1; i++) {
        // if frequency 0 - missing
        // if frequency 2 - repeating
        if (hash[i] > 1)  res[0] = i;
        else if (hash[i] == 0) res[1] = i;
    }
    return res;
}
// TC - O(2n)
// SC - O(n)


// optimal 
// using maths

vector<int> missingRepeating3(vector<int> arr) {
    long long n = arr.size();

    long long sn = (n/2) * (n+1);
    long long s2n = (n/6) * (n+1) * (2*n+1);
    long long s = 0, s2 = 0;

    for (int i=0; i<n; i++) {
        s += arr[i];
        s2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = s - sn; // x - y
    long long val2 = s2 - s2n; //
    val2 = val2 / val1; // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}
// TC -O(n)
// SC -O(1)



// --- optimal
// using bit manupilation
// 1.xor arr[i] ^ (1...n) = num
// 2.find the differentiating bit in num - (its xor will be 1) 
// 3.put them into two parts 0 and 1
// check for repeating and other will be missing

vector<int> missingRepeating4(vector<int> arr) {
    long long n = arr.size();
    int xr = 0;
    for (int i=0; i<n; i++) {
        xr ^= arr[i];
        xr ^= i+1;
    }
     
    // find the bit index where both bits are no equal - every number will have i different bit - which make them unique
    int bitNO = 0;
    while (1) {
        if ((xr & (1<<bitNo)) != 0) {
            break;
        } 
        bitNo++;
    }
    // or use - 
    // int number = xr & ~(xr - 1);

    // group into zero and one 
    int zero = 0;
    int one = 0;

    for (int i=0; i<n; i++) {
        // part of one club
        if ((arr[i] & (1<<bitNO)) != 0) { // use number -> (1<<bitNO)
            one ^= arr[i];
        }
        // part of zero club
        else {
            zero ^= arr[i];
        }
    }

    for (int i=1; i<n+1; i++) {
        // part of one club
        if ((i & (1<<bitNO)) != 0) { // use number
            one ^= i;
        }
        // part of zero club
        else {
            zero ^= i
        }
    }

    // confirm the missing and repeting number
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == zero) cnt++;
    }
    if (cnt == 2) return {zero, one};
    return {one, zero};

}
// TC - O(n) 
// SC - O(1)

int main()  {
    vector<int> arr = {3,1,2,5,4,6,7,5};
    print(missingRepeating(arr));

    return 0;
}
