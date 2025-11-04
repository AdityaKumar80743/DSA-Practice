#include <bits/stdc++.h>

using namespace std;

// -------------- Sum of Beauty of all substring --------
int getBeauty(string &s) {
    unordered_map<char , int> freq;

    // make the frequency map
    for (char ch: s) {
        freq[ch]++;
    }

    // if more than two elements then get min and max frequency
    if (freq.size() >= 2) {
        int maxfreq = 0, minfreq = 0;
        for (const auto pair:freq) {
            // get max 
            maxfreq = max(maxfreq, pair.second);
            // get min
            minfreq = min(minfreq, pair.second);
        }
        return maxfreq - minfreq - 1;
    }
    // only 1 element return
    return 0;
}

int beauty(const string &s) {
    int beauti = 0;

    // get every substring
    for (int i=0; i<s.length(); i++) {
        string substring;
        for (int j=i; j<s.length(); j++) {
            // add char to substring
            substring += s[j];
            // get beauty value of respective substring and add to total beauty
            beauti += getBeauty(substring);
        }
    }
    return beauti;
}
// TC - O(n ^ 3)
// sc - O(1) - can't be more than 52 alphabets (upper and lower case) 


// clean code
int beauty2(string s) {
    int n = s.length();
    int sum = 0;
    // Loop over all substrings
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        for (int j = i; j < n; j++) {
            // Increase frequency of current character
            freq[s[j]]++;
            int maxi = INT_MIN;
            int mini = INT_MAX;
            // Find max and min frequency
            for (auto it : freq) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }
            // Add difference to sum
            sum += (maxi - mini);
        }
    }
    return sum;
}




int main() {
    string s =  "aabcbaa";
    cout << beauty2(s);

    return 0;
}