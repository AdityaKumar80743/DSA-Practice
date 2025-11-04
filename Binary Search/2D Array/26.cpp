#include <iostream>
#include <vector> 

using namespace std;

bool searchRow(vector<int> &row, int target) {
    int low = 0;
    int high = row.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (row[mid] == target) return true; // target found
        else if (row[mid] > target) high = mid - 1; // move left
        else low = mid + 1; // move right
    }
    return false; // not found
}

bool serachMat(vector<vector<int>> &mat, int target) {
    int n = mat.size();
    for (int i=0; i<n; i++) {
        // return if target found
        if (searchRow(mat[i], target)) return true;
    }
    // target not found
    return false;
}
// TC - O(n x logm) 
// SC - O(1)




// --- optimal
// start form top-left or bottom right
// and compare the values and move row and column pointers accordingly

vector<int> serachMat2(vector<vector<int>> &mat, int target) {
    int row = 0;
    int col = mat[0].size() - 1;

    while (row < mat.size() && col >= 0) {
        if (mat[row][col] == target) return {row,col};
        else if (mat[row][col] < target) row++;
        else col--;
    }
    return {-1,-1};
}
// TC - O(n+m) 
// SC - O(1)


int main() {
    vector<vector<int>> mat = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17},
        {18,21,23,26,30}
    };

    for (auto it:serachMat2(mat, 14)) {
        cout << it << " ";
    }



    return 0;
}