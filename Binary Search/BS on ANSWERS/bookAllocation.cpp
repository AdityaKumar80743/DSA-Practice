#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

// ------------------ Book allocation problem -----------------
bool canAllocate(vector<int> &books, int students, int maxPages) {
    int n = books.size();
    int studentNo = 1;
    int pages = 0;

    for (int i=0; i<n; i++) {
        if (pages + books[i] <= maxPages) pages += books[i];
        else {
            studentNo++;
            pages = books[i];
        }
        if (studentNo > students) return false;
    }
    return true;
}

int bookAllocation(vector<int> &books, int students) {
    int n = books.size();
    int low=INT_MIN, high=0;

    // get max and sum of books
    for (int i=0; i<n; i++) {
        low = max(low, books[i]);
        high += books[i];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(books, students, mid)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
// TC - O(n) + O(log(sum(arr) - max(arr))  x  n)  

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int stu = 4;

    cout << bookAllocation(arr, stu);

    return 0;
}
