#include <iostream>
#include <vector>

using namespace std;

// print vector
void print(vector<int> arr) {
    for (auto it:arr) cout << it << " ";
}

// =================== REARRANGE ARRAY ELEMENTS BY SING =================
// --- VARIATION #1
// --- PROBLEM: array have even number of elements 
// array shold start from postive number and alter the postion with negative and postive numbers
// ex- [1,-1, 3,-4]
// the relative order of the elements with respect to their sign elemnts should not change
// [1,2,3,-1,-2,-3]
// ex. [1,-1,2,-2,3-2]

// --- brute
// using two arrays for storing postive, negative numbers
void rearrange(vector<int>& arr) {
    vector<int> pos;
    vector<int> neg;
    int n = arr.size();

    for (int i=0; i<n; i++) {
        if (arr[i] >= 0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }

// positive occupy even indexes and negetive occpuy odd ones
    for (int i=0; i<n/2; i++) {
        arr[2*i] = pos[i];
        arr[2*i +1] = neg[i];
    }
}
// TC - O(n) + O(n) 
// SC - O(n) 


// --- optimal
// using single array
vector<int> rearrange2(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n, 0);
    int posIdx= 0, negIdx= 1;
    
    for (int i=0; i<n; i++) {
        if (arr[i] >= 0) {
            res[posIdx] = arr[i];
            posIdx += 2; // maintain even index for postive numbers
        } 
        else {
            res[negIdx] = arr[i];
            negIdx += 2; // maintain odd index for negative numbers
        }
    }
    return res;
}
// TC - O(n) 
// SC - O(n) 


// ===== # VARIATION # 2
// size of postive and negative numbers are not equal 
// if one type of number ends other type should fill the rest in the end
// ex . [1,2,3,4,5,-1,-2,-3]
// ans - [1,-1,2,-2,3,-3, 4,5]


// make changes in rearrange 1 
void rearrange3(vector<int>& arr) {
    vector<int> pos, neg;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) pos.emplace_back(arr[i]);
        else neg.emplace_back(arr[i]);
    }

    int pn = pos.size(), nn = neg.size();
    int minLen = min(pn, nn);

    // First fill alternating pattern
    for (int i = 0; i < minLen; i++) {
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }

    // Next free index in arr
    int index = 2 * minLen;

    // If positives are left
    for (int i = minLen; i < pn; i++) {
        arr[index++] = pos[i];
    }

    // If negatives are left
    for (int i = minLen; i < nn; i++) {
        arr[index++] = neg[i];
    }
}
// TC - O(n) + O(n) 
// SC - O(n) 

int main() {
    vector<int> arr = {1,-3,-5,2,3,4,-1,-2,1,2,2,3,4,5,6};

    rearrange3(arr);
    print(arr);


    return 0;
}
