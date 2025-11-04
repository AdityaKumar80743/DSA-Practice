#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// -------- Find Peak Element (2D Matrix) -------
vector<int> peak(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int left   = (j - 1 >= 0) ? mat[i][j - 1] : -1;
            int right  = (j + 1 < m)  ? mat[i][j + 1] : -1;
            int top    = (i - 1 >= 0) ? mat[i - 1][j] : -1;
            int bottom = (i + 1 < n)  ? mat[i + 1][j] : -1;

            if (mat[i][j] >= left && mat[i][j] >= right &&
                mat[i][j] >= top && mat[i][j] >= bottom) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}
// TC - O(n x m) 

// --- optimal

int maxElement(vector<vector<int>> &mat, int row) {
    int n = mat[0].size();
    int maxVal = INT_MIN;
    int maxIdx = -1;

    for (int i=0; i<n; i++) {
        if (mat[row][i] > maxVal) {
            maxVal = mat[row][i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

vector<int> peak2(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int col = maxElement(mat, mid);

        int top = mid-1 >= 0 ? mat[mid-1][col] : INT_MIN;
        int bottom = mid+1 < n ? mat[mid+1][col] : INT_MIN;

        if (mat[mid][col] > top && mat[mid][col] > bottom) {
            return {mid, col};
        }
        else if (top > mat[mid][col]) high = mid - 1;
        else low = mid + 1;
    }
    return {-1,-1};
}
// TC - O(logn x m) 

int main() {
    vector<vector<int>> mat = {
        {5, 10, 8},
        {4, 25, 7},
        {3, 9, 6}
    };

    vector<int> ans = peak2(mat);
    cout << "Peak found at: (" << ans[0] << ", " << ans[1] << ")\n";
    cout << "Value: " << mat[ans[0]][ans[1]] << endl;
    return 0;
}
