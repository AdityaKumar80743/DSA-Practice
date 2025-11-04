#include <bits/stdc++.h>

using namespace std;

// ----------- Maximum Nesting Depth of Parenthesis --------

int maxDepth(string &str) {
    int count = 0;
    int ans = 0;

    for (char ch:str) {
        if (ch == '(') count++;
        else if (ch == ')') count--;
        ans = max(ans, count);
    }

    return ans;
}

int main() {
    string str = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(str) << endl;

    return 0;
}