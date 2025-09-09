#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ------------- SUBARRAY ----------
// contigous part of the array 

// print array
void print(int arr[], int n) {
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

// print vector
void printV(vector<int> arr) {
    for (auto it:arr) cout << it << " ";
    cout << endl;
}

// print all subarrays
// brute force 
void subarrays(int arr[], int n) {
    for (int i=0; i<n; i++) {
        vector<int> sub;
        for (int j=i; j<n; j++) {
            sub.emplace_back(arr[j]);
            printV(sub);
        }
    }
}



// ------------------ LONGEST SUBARRAY TO K ------------- 
// PROBLEM: find the longest subarry which sum to k

// --- brute force
int subarrayToK(int arr[], int n, int k) {
    int longest = 0;
    for (int i=0; i<n; i++) {
        int subSum = 0;
        for (int j=i; j<n; j++) {
            subSum += arr[j];
            if (subSum == k) {
                longest = max(j-i+1, longest);
                continue;  // skip current loop - as sum is equal to k after that the subSum will eventually increaes
            } else if (subSum > k) {
                continue; // as subsum is > k - no need to check further
            }   
        }
    }
    return longest;
} 
// TC - O(n^2)
// SC - O(1)


// ---better
// using hashing
// work for minus valus also
int subarrayToK3(int arr[], int n, int k) {
    map<long long, int> hash;
    int longest = 0;
    long long subSum = 0;
    
    for (int i=0; i<n; i++) {
        subSum += arr[i];
    
        if (subSum == k) {
            longest = i+1;
        }
        int ren = subSum - k;
        else if (hash.find(ren) != hash.end()) {
            longest = max(longest, i - hash[ren]);
        }

        // if subSum already exits do not re-update the value of the subsum in hash map
        // ex - [2,0,0,3] - here, 
        // when subsum = <2,0> -> <2,1> -> <2,2> -> <5,0># this is not corrent so avoid it
        // here the out put will be (3-2) = 1 ## Not correct
        // so -- if subsum not changes don't update the hashmap
        if (hash.find(subSum) == hash.end()) hash[subSum] = i;
    }
    return longest;
}
// TC - O(n) for loop
// // O(logn) if used orderd map
// O(nx1) if used unorder map - worst can go till (n^2) - if lots of collisions 
// SC - O(n)

// --- optimal
// two pointers 
int subarrayToK2(int arr[], int n, int k) {
    int start = 0;
    int end = 0;
    long long sum = arr[0];
    int longest = 0;

    while (end <= n) {
        if (sum > k) {
            sum -= arr[start];
            start++;
        } else if (sum < k) {
            end++;
            sum += arr[end];
        } else {
            longest = max(longest, end - start + 1);
            if (end < n) {
                end++;
                sum += arr[end];
            } else {
                sum -= arr[start];
                start++;
            }
        }
    }
    return longest;
}
// TC - O(2n)
// SC - O(1)

// better version of optimal approach
int subarrayToK4(int arr[], int n, int k) {
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;

    while (right < n) {
        while (left < right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n) sum += arr[right];
    }
    return maxLen;
}


int main() {
    int n = 6; 

    int arr[n] = {1,2,1,1,1,3};
    cout << subarrayToK4(arr, n, 3);


    return 0;
}
