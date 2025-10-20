#include <iostream>
#include <vector> 

using namespace std;

// square root a number
int sRoot(int n) {
    int low=0, high=n/2;

    //edge case 1
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sqr = mid * mid;

        if (sqr == n) return mid;
        else if (sqr < n) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

// nth root of m
int nRoot(int n, int m) {
    int low=0, high=m/n;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long multi = 1;
        for (int i=1; i<=n; i++) multi *= mid;

        if (multi == m) return mid;
        else if (multi < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}



int main() {
    cout << sRoot(26) << endl;
    cout << nRoot(3,27) << endl;

    return 0;
}
