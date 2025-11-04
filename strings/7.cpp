#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//----------- Check if two Strings are anagrams of each other ---

bool anagrams(string &a, string &b) {
    if (a.size() != b.size()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
// TC - O(2 x nlogn + n)


// --- optimal
bool anagrams2(string &a, string &b) {
    int n = a.size();
    
    if (n != b.size()) return false;

    int freq[26] = {0};

    for (int i=0; i<n; i++) {
        freq[a[i] - 'A']++;
        freq[b[i] - 'A']--;
    }

    for (int i=0; i<26; i++) {
        if (freq[i] != 0) return false;
    }
    return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";
    if(anagrams2(Str1, Str2))
    cout << "True" << endl;
    else
    cout<<"False"<<endl;

    return 0;
}