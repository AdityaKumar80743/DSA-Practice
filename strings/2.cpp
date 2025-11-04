#include <iostream>
#include <string>
using namespace std;

string reverseWords(const string &str) {
    string res;
    int n = str.size();
    int end = n - 1;

    while (end >= 0) {
        // Skip trailing spaces
        while (end >= 0 && str[end] == ' ')
            end--;
        if (end < 0) break;

        // get start of the word
        int start = end;
        while (start >= 0 && str[start] != ' ')
            start--;

        // Add word to result
        res += str.substr(start + 1, end - start) + ' ';

        // update the pointer
        end = start - 1;
    }

    // Remove space at end (if any)
    if (!res.empty() && res.back() == ' ')
        res.pop_back();

    return res;
}
// tc - O(n)
// sc - O(1)

int main() {
    string str = "my name is aditya";
    cout << reverseWords(str);
    return 0;
}