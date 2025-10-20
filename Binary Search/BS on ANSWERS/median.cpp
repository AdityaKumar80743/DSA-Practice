#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

vector<int> merge(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> merged;

    int p1 = 0;
    int p2 = 0;

    while (p1 < n1 && p2 < n2) {
        if (arr1[p1] <= arr2[p2]) {
            merged.push_back(arr1[p1]);
            p1++;
        }
        else {
            merged.push_back(arr2[p2]);
            p2++;
        }
    }

    while (p1 < n1) merged.push_back(arr1[p1++]);
    while (p2 < n2) merged.push_back(arr2[p2++]);

    return merged;
}

double median(vector<int> &arr1, vector<int> &arr2) {
    vector<int> fullArr = merge(arr1, arr2);
    int n = fullArr.size();

    if (n % 2 == 0) {
        return (double)((double)(fullArr[n/2] + (double)fullArr[n/2 - 1]) / 2.0)
    }
    else return (double)fullArr[n/2];
}
// TC - O(n+m)
// sc - O(n+m)


// ---better
double median2(vector<int> &a, vector<int> &b) {
    int n1 = a.size(), n2=b.size();
    int i=0, j=0;
    int n = (n1 + n2);
    int ind2 = n/2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    while (i<n1 && j<n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }
    while (i<n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j<n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    if (n%2 == 1) return ind2el;
    return (double) ((double)(ind1el + ind2el)) / 2.0; 
}
// tC - O(n + m)
// sc - O(1)

// --- optimal 
double merge3(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();

    // take array with smaller length
    if (n1 > n2) return merge3(b,a);

    int low = 0, high = n1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int al = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int ar = (cut2 == n1) ? INT_MAX : a[cut1];
        int bl = (cut1 == 0) ? INT_MIN : b[cut2 - 1];
        int br = (cut2 = n2) ? INT_MAX : b[cut2]

        if (al > br) high = cut1 - 1;
        else if (ar > bl) low = cut1 + 1;
        else {
            if ((n1 + n2) % 2 == 0) {
                return (max(al,bl) + min(ar,br)) / 2.0;
            }
            else return max(al, bl);
        }
    }
    return 0.0;
}
// tc - O(log(min(n1,n2))) 
// sc - O(1)

int main() {


    return 0;
}
