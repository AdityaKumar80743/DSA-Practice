#include <iostream>
#include <string> 

using namespace std;

// ------------- Remove Outermost Parentheses --------------

string outermost(string &str) {
    string res = "";
    int count = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(' ) {
            count++;
            if ( count >= 2) res += '(';
        } 
        else if (str[i] == ')' ) {
            count--;
            if ( count >= 1) res += ')'; 
        } 
    }
    return res;
}
// tc - o(n)
// sc - O(1)


int main() {
    string str = "((()))";

    cout << outermost(str) << endl;

    return 0;
}