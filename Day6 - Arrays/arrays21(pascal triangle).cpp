#include <iostream>
#include <vector>

using namespace std;

// print vector
void print(vector<int> arr) {
    for (int it:arr) cout << it << " ";
    cout << endl;
}

// print nested vector
void printV(vector<vector<int>> arr) {
    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// ==================== Pascal triangle ================
// VARIATION 1; print the element at nth row and mth column

// using ncr 
int pascalv(int n, int m) {
    long long res = 1;
    while (m >=1 ) {
        res = res * (n/m);
        n--;
        m--;
    }
    return res;
}
// TC - O(m) 
// SC - O(1)

// or 
int ncr(int n, int r) {
    long long ans = 1;
    for (int i=0; i<r; i++) {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
}

// VARIATION 2; print all the elements in the nth row

vector<int> pascalr(int n) {
    vector<int> res = {1};
    long long ans = 1;
    
    for (int i=1; i<=n-1; i++) {
        ans *= n-i;
        ans /= i;
        res.push_back(ans);
    }
    return res;
}
// tc - o(n)
// sc - O(n)


// VARIATION 3; print all the row till nth row

// call above funtion n times
vector<vector<int>> pascaln(int n) {
    vector<vector<int>> res;
    for (int i=1; i<=n; i++) {
        res.push_back(pascalr(i));
    }
    return res;
}
// TC - O(n*n) 
// SC - (n*n) 

int main() {
    int n = 10;
    int m = 3;

    // printV(pascaln(n));
    // print(pascalr(n));
    // cout << ncr(5,3);

    return 0;
}
