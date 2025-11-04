#include <iostream>
#include <vector> 

using namespace std;

// ----------- Find the row with maximum number of 1's -----

// --- brute force
int oneRow(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int curMax = 0;
    int ans = -1;

    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<m; j++) {
            if (mat[i][j] == 1) count++;
        }
        if (count == m) return i;
        if (count > curMax) {
            curMax = count;
            ans = i;
        }
    }
    return ans;
}
// TC - O(n*m)
// sc - O(1)


// --- optimal solution
int oneRow2(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int curMax = 0;
    int ans = -1;

    for (int i=0; i<n; i++) {
        int low = 0; 
        int high = m-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[i][mid] == 1) high = mid - 1;
            else low = mid + 1;
        }

        if (low == 0) return 0;
        if (m-low > curMax) {
            curMax = m-low;
            ans = i;
        }
    }
    return ans;
}
// tc - O(n*log(m)) 
// sc - O(1)

int main() {
    vector<vector<int>> mat = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    cout << oneRow2(mat) << endl;

    return 0;
}