#include <iostream>
#include <string>
#include <map>

using namespace std;

// ------------- Isomorphic String -------------

// wo strings s and t are isomorphic
// if the characters in s can be replaced to get t.

bool isIsomorphic(string &a, string &b) {
    int n = a.size();
    int m = b.size();

    if (n != m) return false;

    map<char, char> hash;

    for (int i = 0; i<n; i++) {
        auto it_char = hash.find(a[i]);

        if (it_char != hash.end()) {
            if (it_char -> second != b[i]) {
                return false;
            }
        }
        else {
            hash[a[i]] = b[i];
        }
    }
    return true;
}


// --- better 
bool isIsomorphic(const string &a, const string &b) {
    if (a.size() != b.size()) return false;

    unordered_map<char, char> mapAB;
    unordered_map<char, char> mapBA;

    for (int i = 0; i < a.size(); i++) {
        char chA = a[i];
        char chB = b[i];

        if (mapAB.count(chA) && mapAB[chA] != chB) return false;
        if (mapBA.count(chB) && mapBA[chB] != chA) return false;

        mapAB[chA] = chB;
        mapBA[chB] = chA;
    }

    return true;
}
// tc - O(n)
// sc - O(1)

// --- optimal
bool isIsomorphic(string s, string t) {
    // Arrays to store last seen positions of characters in s and t
    int m1[256] = {0}, m2[256] = {0}; 
    
    // Get the length of the strings
    int n = s.size(); 
    
    // Traverse each character of the strings
    for (int i = 0; i < n; ++i) {
        // If previous positions of current characters differ, return false
        if (m1[s[i]] != m2[t[i]]) return false;
        
        // Update the position with current index + 1
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    
    // If no mismatch is found, return true
    return true;
}

int main() {
    string s = "paper", t = "title";
    cout << boolalpha << isIsomorphic(s, t) << endl; // Output: true
    return 0;
}
