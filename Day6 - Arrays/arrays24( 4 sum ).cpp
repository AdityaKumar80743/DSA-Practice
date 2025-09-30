#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// print vector
void print(vector<vector<int>> &arr) {
    for (auto v:arr) {
        cout << "[";
        for (auto it:v) {
            cout << it << " ";
        }
        cout << "]";
    }
    cout << endl;
}

// ================= 4 SUM ===================
vector<vector<int>> sum4(vector<int> arr, int target) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i=0; i<n; i++) {
        if (i>0 && arr[i] == arr[i-1]) continue;
        for (int j=i+1; j<n; j++) {
            if (j > i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while (k<l) {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while (k<l && arr[k] == arr[k-1]) k++;
                    while (k<l && arr[j] == arr[j+1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}
// TC - O(n^3)
// SC - O(1) - to solve the problem  

int main() {
    vector<int> arr = {1,2,3,-1,-2,-3};
    int target = 0;
    vector<vector<int>> ans = sum4(arr, target);
    print(ans);


    return 0;
}
