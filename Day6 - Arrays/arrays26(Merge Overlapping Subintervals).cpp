#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << "[";
        for (int j=0; j<arr[i].size(); j++) {
            cout << arr[i][j] << ",";
        }
        cout << "]" << endl;
    }
}

void prints(set<int> st) {
    for (int it:st) cout << it << " ";
    cout << endl;
}

// =============== Merge Overlapping Sub-intervals ==============

// using set
vector<vector<int>> merge(vector<vector<int>> arr) {
    set<int> st;
    vector<vector<int>> res;

    // get all the unique nums in the intervals 
    for (int i=0; i<arr.size(); i++) {
        for (int j=arr[i][0]; j<=arr[i][1]; j++) {
            st.insert(j);
        }
    }

    vector<int> interval;
    int prev = *st.begin();
    for (int it:st) {
        // end the interval if there is discontinuty
        if (it - prev > 1 ) {
            interval.push_back(prev); // close interval
            res.push_back(interval);
            interval.clear();
        }
        // close the interval if last element reached
        else if ( it == *st.rbegin()) {
            interval.push_back(it);
            res.push_back(interval);
        }
        // push new interval
        if (interval.size() == 0) interval.push_back(it); // start interval
        prev = it;
    }
    return res;
}
// TC - O(klogk) where k is all nums in each interval
// TC O(k) 


// sorting the main array 
vector<vector<int>> merge2(vector<vector<int>> arr) {
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
});
    print(arr);
    cout << endl;

    vector<vector<int>> res = {arr[0]};

    for (int i=1; i<arr.size(); i++) {
        bool changed = false;
        for (int j=0; j<res.size(); j++) {
            
            if (arr[i][0] >= res[j][0] && arr[i][0] <= res[j][1]) {
                res[j][1] = arr[i][1];
                changed = true;
            }
            if (arr[i][0]-1 == res[j][1]) {
                res[j][1] = arr[i][1];
                changed = true;
            }
        }
        if (!changed) res.push_back(arr[i]);
    }
    return res;
}
// TC - O(n x n) 
// SC - O(n) 


// best version of above 
vector<vector<int>> merge3(vector<vector<int>> arr) {
    // Sort by start, then by end
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    // initialize result with first interval
    vector<vector<int>> res = {arr[0]};

    for (int i = 1; i < arr.size(); i++) {
        // Compare with the last interval in res
        if (arr[i][0] <= res.back()[1]) {
            // Overlap -> merge
            res.back()[1] = max(res.back()[1], arr[i][1]);
        } else {
            // No overlap -> push new interval
            res.push_back(arr[i]);
        }
    }
    return res;
}
// TC - O(nlogn) 
// Sc - O(n) 


int main() {
    vector<vector<int>> arr = {{1,4}, {2,6}, {8,10}, {9,11}, {2,7}, {19, 20}};
    print(merge2(arr));

    return 0;
}
