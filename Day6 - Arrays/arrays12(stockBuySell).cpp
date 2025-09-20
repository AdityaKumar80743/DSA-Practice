#include <iostream> 
#include <algorithm>
#include <climits>

using namespace std;

// ================== BEST TIME TO BUY AND SELL STOCKS ================
// ===================== SINGLE TRANSACTION =====================
// PROBLEM: buy the stocks and sell them on some other day to make profit
// stocks should be sold after buying the stocks 


// --- brute force 
int stockBuySell(int arr[], int n) {
    int profit = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[j] > arr[i]) {
                profit = max(profit, arr[j] - arr[i]);
            }
        }
    }
    return profit;
}
// TC - O(n^2)
// SC - O(1) 

// --- optimal
int stockBuySell2(int arr[], int n) {
    int mini = arr[0], profit = 0;

    for (int i=0; i<n; i++) {
        profit = max(profit, arr[i] - mini);
        mini = min(mini, arr[i]); // keep track of the minimum 
    }
    return profit;
}
// TC - O(n) 
// SC - O(1)

int main() {
    int n = 6;
    int arr[n] = {7,1,5,3,6,4};

    cout << stockBuySell2(arr, n);

    
    return 0;
}
