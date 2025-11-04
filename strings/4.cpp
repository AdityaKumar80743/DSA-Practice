#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ----------- Longest Common Prefix -------------

string prefix(vector<string> &words) {
    int n = words.size();
    if (n == 0) return "";
    if (n == 1) return words[0];

    string pre = words[0];

    for (int i = 1; i < n; i++) {
        int j=0;

        while (j < pre.size() && j < words[i].size() && pre[j] == words[i][j]) j++;
        // pre = pre.substr(0,j);
        // don't create new string each time 
        // instead trim the string
        pre.resize(j);

        // return if pre is empty
        if (pre.empty()) return "";
    }
    return pre;
}
// tc - O(nXm) n = no. of words , m = shortest string size;
// sc - O(a)) a = size of first string

int main() {
    vector<string> words = {"flower", "flow", "flight"};

    cout << prefix(words) << endl;

    return 0;
}