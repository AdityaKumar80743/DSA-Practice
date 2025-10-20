#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// ------------- kth element in two sorted arrays -------------
int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n1 = a.size();
    int n2 = b.size();

    // Always binary search on the smaller array
    if (n1 > n2) return kthElement(b, a, k);

    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

        if (l1 > r2) {
            high = cut1 - 1;
        } 
        else if (l2 > r1) {
            low = cut1 + 1;
        } 
        else {
            return max(l1, l2);
        }
    }

    return -1;
}
// Time Complexity: O(log(min(m, n)))


int main() {


    return 0;
}
