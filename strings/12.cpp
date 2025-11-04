#include <bits/stdc++.h>

using namespace std;

// ----------------- Count Number of Substrings -----------

int substring(string &s, int k) {
    int n = s.size();
    int count = 0;

    for (int i=0; i<n; i++) {
        
        unordered_map<int, char> freq;
        for (int j=i; j<n; j++) {
            if (freq.size() <= k) {
                freq[s[j]]++;
                if (freq.size() == k) count++;
            }      
            else break;
        }
    }
    return count;
}
// tc - O(n^2)
// sc - O(1)

int substring2(string &s, int k) {
    int n = s.size();
    int count = 0;

    unordered_map<char, int> freq;
    int low = 0;
    int high = 0;

    while (low < n && high < n) {
        freq[s[low]]++;
        if (freq.size() <= k) high++;
        else low++;
    }
}

int main() {
    string s = "pqpqs";
    int k = 2;

    cout << substring(s, k);

    return 0;
}