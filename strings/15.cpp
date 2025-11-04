#include <bits/stdc++.h>

using namespace std;

// --------- Reverse Every Word in A String ---------- 

string rev(const string &s) {
    int n = s.length();
    string ans;

    // start form end (last character)
    int end = n-1;

    while (end > 0) {
        // iterate until a char is found - (end point of a word)
        while (s[end] == ' ' ) {
            // keep moveing left
            end--;
            // add the spaces
            ans += ' ';
        }

        // get starting point of the word
        int start = end;

        // move the point to left until a space is found - (start point of a word)
        while (s[start] != ' ' && start >= 0) start --;

        // append the word to ans 
        ans += s.substr(start + 1, end - start);
        
        // reset the end pointer to the start of the current word
        end = start;

        // repeat the logic until starting point of the string is reached
    }
    return ans;
}
// TC - O(n)
// SC - O(n)


int main() {
    string s =  "welcome to the jungle";

    cout << rev(s) << endl;

    return 0;
}