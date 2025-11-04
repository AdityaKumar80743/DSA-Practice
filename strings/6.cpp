#include <iostream>
#include <string>

using namespace std;

// ------------ Check if one string is rotation of another ------

bool rotate(string &s, string &goal) {
    int n = s.size();
    int m = goal.size();

    if (n != m) return false;

    int p = 0;

    for (int i=0; i<n; i++) {
        if (s.substr(p,n) == goal) return true;
        s += s[p];
        p++; 
    }
    return false;
}
// logical error


// --- optimal
bool rotate2(string &s, string &goal) {
    if (s.size() != goal.size()) return false;
    return (s+s).find(goal) != string::npos;
}
// tc - O(n) 
// sc - O(2n)

int main() {
    string s = "roatation";
    string goal = "tionroata";

    cout << rotate2(s,goal) << endl;


    return 0;
}