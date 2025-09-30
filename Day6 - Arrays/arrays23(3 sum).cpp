#include <iostream>
#include <vector>
#include <set>
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

// ================= 3 SUM ==============
// 3 elements which sum to 0;

// --- brute 
// generate every tripelet and check if there sum is 0
vector<vector<int>> sum3(vector<int> arr) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // make sure no duplicates values
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// TC - O(n^3)
// SC - O(2 x no.of tripelts)


// --- better 
// using hashing
vector<vector<int>> sum32(vector<int> arr) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i=0; i<n; i++) {
        set<int> hashset;
        for (int j=i+1; j<n; j++) {
            int third = -(arr[i] + arr[j]);

            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// TC - O(n^2 + logn)
// SC - O(N) + O(2 x no.of tripelet) 


// --- optimal 
// three pointer
vector<vector<int>> sum33(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;

    for (int i=0; i<n; i++) {
        if (i>0 && arr[i] == arr[i-1]) continue; // skip duplicate of i
        int j = i +1;
        int k = n -1;
        while (j<k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0) j++;
            else if (sum > 0) k--;
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                res.push_back(temp);
                j++;
                k--;

                // skip duplicates 
                while (j<k && arr[j] == arr[j-1]) j++;
                while (j<k && arr[k] == arr[j+1]) k--;
            }
        }
    }
    return res;
}
// TC - O(n^2)
// SC - O(1)


int main() {
    vector<int> arr = {1,2,3,-1,-2,-3};
    vector<vector<int>> ans = sum33(arr);
    print(ans);


    return 0;
}
