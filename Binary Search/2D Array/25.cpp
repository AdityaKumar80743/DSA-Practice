#include <iostream>
#include <vector> 

using namespace std;

// ------------------ search in 2d matrix -----------------

int searchRow(vector<int> &row, int target) {
    int low = 0;
    int high = row.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (row[mid] == target) return 1;
        else if (row[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    if (high == -1) return 0; // may be on left side;
    else if (high == row.size() - 1) return 2; // may be on right side
    return -1; // not found
}

bool serachMat(vector<vector<int>> &mat, int target) {
    int low = 0;
    int high = mat.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = searchRow(mat[mid], target);

        if (res == 1) return true; // found
        else if (res == 0) high = mid - 1;
        else if (res == 2) low = mid + 1;
        else return false;
    }
    return false;
}
// TC - O(log(n) x log(m)) 


// --- optimal 
// 2d to 1d array

bool searchMatrix(vector<vector<int>> &mat, int target) {
    if (mat.empty() || mat[0].empty()) return false;

    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / cols;
        int col = mid % cols;

        int val = mat[row][col];
        if (val == target) return true;
        else if (val < target) low = mid + 1;
        else high = mid - 1;         
    }
    return false;
}
// Tc - O(log(mxn))


int main() {
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    cout << searchMatrix(mat, 1) << endl;


    return 0;
}