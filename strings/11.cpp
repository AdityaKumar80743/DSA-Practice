#include <bits/stdc++.h>
using namespace std;

// implement ATOI

int atoii(string &str) {
    long long ans = 0;
    int sign = 1;
    bool started = false; 

    for (char ch : str) {

        if (!started && ch == ' ') continue; 

        if (!started && (ch == '-' || ch == '+')) {
            sign = (ch == '-') ? -1 : 1;
            started = true;
            continue;
        }

        if (!isdigit(ch)) break;

        started = true;
        ans = ans * 10 + (ch - '0');

        // Overflow check (32-bit)
        if (ans * sign > INT_MAX) return INT_MAX;
        if (ans * sign < INT_MIN) return INT_MIN;
    }

    return (int)(ans * sign);
}
// TC O(n)
// sc O(1)


int myAtoi(string s) {
    int i = 0, sign = 1;
    long result = 0;

    //  Skip leading spaces
    while (i < s.length() && s[i] == ' ')
        i++;

    //Optional sign
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    //  Convert digits
    while (i < s.length() && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');

        // Check overflow
        if (result > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        i++;
    }

    return (int)(result * sign);
}


int main() {
    string s = "1337c0d3";
    cout << atoii(s) << endl; 
    return 0;
}
