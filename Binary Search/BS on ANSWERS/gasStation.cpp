#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

// --------- Minimise Maximum Distance between Gas Stations

// --- brute
int gasStation(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> sections(n-1,0);

    for (int i=1; i<=k; i++) {
        long double maxVal = -1;
        int maxIdx = -1;
        for (int i=0; i<n-1; i++) {
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = diff / (sections[i] + 1);
            if (sectionLength > maxVal) {
                maxVal = sectionLength;
                maxIdx = i;
            }
        }
        sections[maxIdx]++;
    }

    // get the max 
    long double maxAns = -1;
    for (int i=0; i<n-1; i++) {
        long double sectionLength = (arr[i+1] - arr[i]) / (sections[i] + 1);
        maxAns= max(maxAns, sectionLength);
    }
    return maxAns;
}
// TC - O(k x n) 
// sC - O(n-1)
// time limit exceded


// --- better
// using data structure 
// pushing in priority_queue take logn time
// pq.top() give max value
// pq.pop() remove top most element
int gasStation2(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> sections(n-1,0);
    priority_queue<pair<long double,int>> pq;

    for (int i=1; i<=k; i++) {
        pq.push({arr[i+1] - arr[i],i});

    }

    for (gasStations = 1; gasStations<=k; gasStations++) {
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        sections[secInd]++;
        long double iniDiff = arr[secInd+1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(sections[secInd]+1);
        pq.push(newSecLen, secInd);
    }
    
    return pq.top().first;
}
// TC - O(nlogn) + O(klogn) 
// SC - O(n-1)


// --- optimal 

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}


int main() {


    return 0;
}
