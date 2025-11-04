#include <iostream>
#include <vector> 

using namespace std;

// -------------- median of row wise sorted matrix --------------

int blackbox(vector<vector<int>> &mat, int x) {
    int n = mat.size():
    int m = mat[0].size();
    int count = 0;

    for (int i=0; i<n; i++) {
        int low = 0; 
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mat[i][mid] <= x) low = mid + 1;
            else high = mid - 1;
        }
        count+=low;
    }
    return count;
}
// TC - O(log(10^9) x n x logm) 


int median(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int req = (n+m) / 2;
    int low = INT_MAX, int high = INT_MIN;

    for (int i=0; i<n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        smallestEquals = blackbox(mat, mid);

        if (smallestEquals <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {


    return 0;
}