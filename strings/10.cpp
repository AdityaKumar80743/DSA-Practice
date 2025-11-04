#include <bits/stdc++.h>

using namespace std;

// ---------------- Roman Numerals to Integer ---------------

int getRoman(char ch) {
    if (ch == 'I') return 1;
    else if (ch == 'V') return 5;
    else if (ch == 'X') return 10;
    else if (ch == 'L') return 50;
    else if (ch == 'C') return 100;
    else if (ch == 'D') return 500;
    else if (ch == 'M') return 1000;
    return 0;
}

int romanToInt(string &str) {
    int ans = 0;
    for (int i=0; i<str.size(); i++) {
        int rom = getRoman(str[i]);
        if (rom < getRoman(str[i+1])) {
            ans += getRoman(str[i+1]) - rom;
            i++;
        }
        else ans += rom;
    }

    return ans;
}

// tc - O(n) 
// sc - O(1) 


int romanToInt(string s) {
    int res = 0;
    // Map of Roman numerals to their integer values
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    // Iterate through the string, except the last character
    for (int i = 0; i < s.size() - 1; i++) {
        // Subtract if current numeral is less than the next
        if (roman[s[i]] < roman[s[i + 1]]) {
            res -= roman[s[i]];
        } else {
            // Otherwise, add the current value
            res += roman[s[i]];
        }
    }
    // Add the value of the last character
    return res + roman[s.back()];
}


int main() {
    string  s = "MCMXCIV";

    cout << romanToInt(s) << endl;

    return 0;
}