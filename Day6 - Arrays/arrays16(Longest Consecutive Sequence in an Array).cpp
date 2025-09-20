#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// =============== LONGEST CONSECUTIVE SEQUENCE IN A ARRAY ==============
// EX : [1,3,100,2,200,4] 
// ANS : [1,2,3,4]

// --- brute force 

// linear search to find the next number in the sequence
bool linearSearch(vector<int> arr, int n, int target) {
    for (int i=0; i<n; i++) {
        if (arr[i] = target) return true;
    }
    return false;
}

int longestSequence(vector<int> arr) {
    int n = arr.size();
    int longest = 0;

    for (int i=0; i<n; i++) {
        int target = arr[i];
        int curLongest = 1;
        
        // linear search until next number in the sequence in not found
        while (linearSearch(arr, n, target+1) == true) {
            curLongest++;
            target++;
        }
        longest = max(longest, curLongest);
    }
    return longest;
}
// TC - O(n^3) - very bad
// SC - O(1)



// --- better 
// sort the array
// all the sequence will in order 
int longestSequence2(vector<int> arr) {
    sort(arr.begin(), arr.end()); // sort the array

    int n = arr.size();
    int longest = 1; // every element is a sequence
    int curLongest = 1;
    for (int i=1; i<n; i++) {
        // check if previous element is part of the sequence or not 
        if (arr[i] - arr[i-1] == 1) { 
            curLongest++; // update longest sequence streak
        } else {
            longest = max(longest, curLongest); // take the maximum longest
        }
    }
    return longest;
}
// TC - O(nlogn) + O(n) 
// SC - O(1)


// ---- optimal 
// using hash set - it takes O(1) to find a number in the set 
// as it works as linked list - it do not search the whole list like linear search

int longestSequence3(vector<int> arr) {
    // copy all the elements in the hash set | TC - O(n)
    unordered_set<int> hash(arr.begin(), arr.end()); 
    int longest = 0;

    for (int num:arr) { // TC - O(n)
        // if previous num do not exit start the sequence
        if (hash.find(num-1) == hash.end()) {
            int curNum = num;
            int curLen = 1;

            // find all the numbers in the sequence 
            // Total TC - O(n) 
            while (hash.find(curNum + 1) != hash.end()) {
                curNum++;
                curLen++;
            }
            longest = max(longest,curLen);
        }
    }
    return longest;
}
// TC - O(n) + O(n) + O(n) = O(3n) 
// 1. insering in hash set
// looping the while array
// hash.find(x) - every element is atleast visited once - average TC for find is O(1) - so TC = O(n)

// SC - O(n)

//*** this solution might look similar to brute force but find the next element in hash set is way faster than linear search


int main() {
    vector<int> arr = {1,3,100,2,200,4};
    int ans = longestSequence3(arr);
    cout << ans << endl;

    return 0;
}
