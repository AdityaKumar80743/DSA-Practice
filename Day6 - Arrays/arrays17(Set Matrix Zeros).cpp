#include <iostream>
#include <vector>

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
}

// print vector
void printV(vector<int> arr) {
    for (int it:arr) cout << it << " ";
    cout << endl;
}

// =================== SET MATRIX =====================
// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.


// --- brute
// mark all the elements in the respective rows and colums with -1 and then iterate again through the matrix and change the marked values with 0

// mark the rows
void changeRow(vector<vector<int>>& arr, int n, int m, int i) {
    for (int j=0; j<m; j++) {
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}
// mark the columns
void changeColumn(vector<vector<int>>& arr, int n, int m, int j) {
    for (int i=0; i<n; i++) {
        if (arr[i][j] != 0) {
            arr[i][j] = -1;
        }
    }
}
// main..
vector<vector<int>> setMatrix(vector<vector<int>>& arr, int n, int m) {

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                changeRow(arr, n, m, i);
                changeColumn(arr, n, m, j);
            }
        }
    }
    // replace markers (-1) with 0
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}
// TC - O((n*m)* (n+m)) + O(n*m)
// SC - O(1)


// --- better 
// using hashing for rows and colums
// marks the row and column seperatly where 0 occurs
vector<vector<int>> setMatrix2(vector<vector<int>> matrix, int n, int m) {

    vector<int> rhash(n,0); // for row
    vector<int> chash(m,0); // for column

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 0) {
                // mark the index of row and column where 0 occurs
                rhash[i] = 1;
                chash[j] = 1;
            }
        }
    }
    // update the matix element to 0, if in the hash map
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (rhash[i] == 1 || chash[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
// TC - O(2(n*m)) 
// SC - O(n+m)


// --- optimal 
// make the first row as row hash 
// make the first column as column hash
// as matrix[0][0] will collide - create variable col0 to store fisrt row fist element
// iterate through the matrix except the hash part (where n=m=0)
// lastly change the hashmap - change the row column hash first as it depends on row hash

vector<vector<int>> setMatrix3(vector<vector<int>> matrix, int n, int m) {

    int col0 = 1; // first element of column hash - acts as matrix[[0][0];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // make the row
                if (j==0) {
                    col0 = 0;
                } else {
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (matrix[i][j] != 0) { // check for non-zero elements
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // fist check the colum hash as it depends on the first elemtnt of the row set of (matrix[0][0])
    if (matrix[0][0] == 0) {
        for (int j=0; j<m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i=0; i<n; i++){
            matrix[i][0] = 0;
        }
    }
    return matrix;
}
// TC - O(2(n*m)) 
// SC - O(1)

int main() {
    vector<vector<int>> arr = {{1,1,1},{1,0,1},{1,1,1}};
    int n = arr.size();
    int m = arr[0].size();
    print(arr);
    cout << endl;

    vector<vector<int>> arrr = setMatrix3(arr,n,m);
    print(arrr);

    return 0;
}
