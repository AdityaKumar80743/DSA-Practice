#include <iostream>
#include <string>

using namespace std;

string largestOdd(string &str) {
    int n = str.length();
    int end = n - 1;

    // move end backward until we find an odd digit
    // subracting with zero to get original value of "n"
    while (end >= 0 && ((str[end] - '0') % 2 == 0)) end--;

    if (end < 0) return "-1";  // no odd digit found

    int start = 0;
    // remove leading zeros
    while (start < n && str[start] == '0') start++; 

    // all zeros before the first odd digit
    if (start > end) return "-1"; 

    return str.substr(start, end - start + 1);
}
// tc - O(n)
// sc - O(1)

int main() {
    string str = "000000066666";
    cout << largestOdd(str) << endl;  // Output: -1
    return 0;
}
