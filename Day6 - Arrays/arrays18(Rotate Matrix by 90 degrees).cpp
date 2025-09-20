#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// print Matrix
void print(vector<vector<int>> arr) {
    int n = arr.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// =============== ROTATE MATRIX 90 DEG =================
// also similar to rotating a image while editing - 
// there pixels represents matrix which can rearranged for rotation.

// --- brute
// using another matirx with all values zero;
// as iterate through the original matrix add the element to the zeor matrix to their respective postions
vector<vector<int>> rotateMatrix(vector<vector<int>> matrix, int n, int m) {
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            res[j][m-i-1] = matrix[i][j];
        }
    }
    return res;
}
// TC - O(n*m) 
// SC O(n*m)



// --- optimal 
// transpose the matrix (interchange the row and columns)
// reverese the row
vector<vector<int>> rotateMatrix2(vector<vector<int>> matrix, int n) {
    // transpose the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {   // j<i ensures only lower triangle
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    // reverse the rows
    // reverse using std;
    for (int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}
// TC - O(2(n*n))
// SC - O(1)



// ex. 4x4 matrix: {{1,2,3,4},{5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    print(matrix);
    cout << endl;

    print(rotateMatrix2(matrix, matrix.size()));



    return 0;
}
