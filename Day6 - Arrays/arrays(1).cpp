// Largest element in a array
int largestElem(int arr[], int n) {
    int maxElem = arr[0];
    for (int i=1; i<=n; i++) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

// Second largest element
int secondLargest(int arr[], int n) {
    // if (arr.size() < 2) return -1;

    int first = arr[0];
    int second;

    for (int i=1; i<=n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        if (first > arr[i] && arr[i] > second) {
            second = arr[i];
        }
    }
    return second;
}

// check if sorted
bool isSorted(int arr[], int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}

// remove duplicates
void removeDuplicates(int arrr[], int n) {
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i] = arrr[i];
    }


    int pointer = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == arr[i+1]) {
            pointer += 1;

            int temp = arr[pointer];
            arr[pointer] = arr[i];
            arr[i] = temp; // swap
        }
    }
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

