#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// print vector
void print(vector<int> arr) {
    for (int it:arr) cout << it << " ";
    cout << endl;
}

// ===================== MAJORITY ELEMENT > N/3 =================

// --- brute force
vector<int> majority(vector<int> arr) {
    int n = arr.size();
    vector<int> res;

    for (int i=0; i<n; i++) {
        int elem = arr[i];
        int count = 1;
        for (int j=i+1; j<n; j++) {
            if (arr[j] == elem) count++;
        }

        if (count > n/3) {
            if (find(res.begin(), res.end(), elem) == res.end()) res.push_back(elem);
        }
    }
    return res;
}
// TC - O(n^2) 
// SC - O(1) - as at max only 2 elements can be majority element (moore voting algo)



// --- better approach
// using hasing 
// store count of all elements
// check for elements whoes count > n/3

// TC - O(n + n)
// SC - O(n) 



// --- optimal
// updated version of majority ( > n/2)
// same logic but for 2 elements
vector<int> majority2(vector<int> arr) {
    int n = arr.size();
    vector<int> res;

    int elem1 = INT_MIN, elem2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    for (int i=0; i<n; i++) {
        if (cnt1 == 0 && arr[i] != elem2) { // don't collide elem1 and elem2
            elem1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && arr[i] != elem1) {
            elem2 = arr[i];
            cnt2 = 1;
        }
        else if (arr[i] == elem1) cnt1++;
        else if (arr[i] == elem2) cnt2++;

        else {
            cnt1--;
            cnt2--;
        }
    }

    // check if majoirty or not
    cnt1 = 0, cnt2 = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == elem1) cnt1++;
        if (arr[i] == elem2) cnt2++;
    }

    int mini = n/3;
    if (cnt1 >= mini) res.push_back(elem1);
    if (cnt2 >= mini) res.push_back(elem2);

    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return res;
}
// TC - O(2n)  
// SC - O(1) - as at max 2 elements possible 


int main() {
    vector<int> arr = {1,1,1,1,3,2,2,2,2};
    vector<int> ans = majority2(arr);
    // cout << ans[0] << " " << ans[1] << endl;

    print(ans);
 
    return 0;
}
