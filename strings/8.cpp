#include <bits/stdc++.h>

using namespace std;

// ------------- Sort characters by frequency -------

bool comparator(pair<int,char> p1, pair<int, char> p2) {
    if (p1.first > p2.first) return true;
    if (p1.first < p2.first) return false;
    return p1.second < p2.second;
}

vector<char> sortByFreq(string &str) {
    pair<int, char> freq[26];

    for (int i=0; i<26; i++) {
        freq[i] = {0,i+'a'};
    }

    for (char ch: str) {
        freq[ch - 'a'].first++;
    }

    sort(freq, freq+26, comparator);

    vector<char> ans;
    for (int i=0; i<26; i++) {
        if (freq[i].first > 0) ans.push_back(freq[i].second);
    }
    
    return ans;
}
// tc - O(n + nlogn)
// O(n)

int main() {
    string s = "tree";

    // Get the sorted characters by frequency
    vector<char> result = sortByFreq(s);

    // Print the result
    for (char c : result) {
        cout << c << " ";
    }

    return 0;
}