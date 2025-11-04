#include <bits/stdc++.h>

using namespace std;

// --------------- Longest Palindromic Substring ------------

// --- brute
int checkPalindrome(string &s, int i, int j) {
    int len = 0;

    while (i<j) {
        if (s[i] != s[j]) return -1;
        else i++; j--; len++;
    }
    return len;
} 

string longestPalindrome(string &s) {
    int n = s.size();
    if (n == 1) return s;

    int low = 0;
    int high = n-1;
    int maxlen = 0;
    int start, end;

    for (int i=0; i<n; i++) {
        for (int j=n-1; j>i; j--) {
            if (s[j] == s[i]) {
                int lenPalin = checkPalindrome(s, i,j);
                if (lenPalin > 0) {
                    if (lenPalin > maxlen) {
                        return s.substr(i , j-i + 1);
                    }
                }
            }
        }
    }
    return "none";
}
// tc - O(n^3) 
// sc - O(1)


// --- optimal

int expandFromCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome2(string &s) {
    int start = 0, end = 0;

    for (int center = 0; center < s.length(); center++) {
        int lenOdd = expandFromCenter(s, center, center);
        int lenEven = expandFromCenter(s, center, center+1);
        int maxlen = max(lenOdd, lenEven);

        if (maxlen > end - start) {
            start = center - (maxlen - 1) / 2; 
            end = center + (maxlen / 2);
        }
    }
    return s.substr(start, end - start + 1);
}
// tc - O(n x x)
// sc - O(1)


int main() {
    string s = "csamadamasdccc";
    cout << longestPalindrome2(s);

    return 0;
}