#include <iostream>
#include <vector>

using namespace std;

// print Matrix
void print(const vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();  
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// print array
void printV(const vector<int>& arr) {
    for (int it:arr) cout << it << " ";
    cout << endl;
}

// ============ SPIRAL TRANSVESAL OF MATRIX =================
// move right -> down -> left -> up
vector<int> spiral(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, right = m-1;
    int top = 0, bottom = n-1;

    vector<int> ans;

    while (top <= bottom && left <= right) {

        // move right
        for (int i= left; i<= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // move down
        for (int i= top; i<= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // move left
        if (top <= bottom) {
            for (int i= right; i>= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // move up
        if (left <= right) {
            for (int i=bottom; i>= top; i--) {
                ans.push_back(matrix[i][left]);
            } 
            left++;
        }
    }

    return ans;
}  
// tc - o(N*M) 
// SC - O(1) 

int main() {

    vector<vector<int>> mat = {{ 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 }};

    print(mat);
    printV(spiral(mat));

    return 0;
}
