#include <iostream>
#include <vector>

using namespace std;

// print vector
void print(vector<int> arr) {
    for (auto it:arr) cout << it << " ";
}

// ================== LEADERS IN A ARRAY ================= 
// PROBLEM: all the right elements from the element should be less than that element
// ex: [17,4,3,5,2,1] here the leaders are 17, 5, 1

// --- brute 
vector<int> leaders(vector<int> arr) {
    int n = arr.size();
    vector<int> res;

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (arr[i] < arr[j]) {
                break;
            }
            else if (j==n-1){
                res.push_back(arr[i]);
            }
        }
    }
    return res;
}
// TC - O(n^2) 
// SC - O(n) - worst case - all are leaders 
// not considering space using to return the answer


// --- optimal 
// start from end and move toward start 
// check if the element iterated through are greater than the previous or not
// if yes then it is a leader, else not

vector<int> leaders2(vector<int> arr) {
    int n = arr.size() - 2; // start form 2nd last element
    vector<int> res;

    for (int i=n; i>=0; i--) {
        if (arr[i] > arr[i+1]) {
            res.push_back(arr[i]);
        }
    }
    return res;
}
// TC - O(n) 
// SC - O(n) 
// sc can be O(1) if not returning the answer and just displaying it on the screen



int main() {
    vector<int> arr = {10,22,13,3,0,6};
    print(leaders(arr));

    return 0;
}
