// -------------------------  Sorting algo's
// ---------- Selection sort - select minimum val for unsorted part more at respective 0 index

void selectionSort(vector<int> arr, int size) {
    for (int i=0; i<size-1; i++) {
        int minIndex = i;
        for (int j=i; j<size; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        arr.swap(arr[i], arr[minIndex]);
    }
}

// --------------- Bubble sort
// moving the largest elemet at the last then reduce the list 
// as right end is already sorted
// if isSwaped = false for optimization is list is already sorted
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i=n-1; i => 0; i--) {
        for (int j=0; j<=i-1; j++) {
            if (arr[j] > arr[j+1]) {
                arr.swap(arr[j], arr[j+1]);
            }
        }
    }
}

// ------------------ (Insertion sort) 
// take the element and place it at it's correct position
// 1st elem is always sorted
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i=1; i<=n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            arr.swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

//-------------------  Merge sort
// divide and merge

// using recurssion - backtracking

// merging
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid +1;

    while (left <= mid && right <= low) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid){
        temp.push_back(left);
        left++;
    }
    while (right <= low) {
        temp.push_back(right);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// dividing
void mergeSort(vector<int> &arr, int start, int end) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid+1, low):

    merge(arr, low, mid, high);
}

// TC = divide takes O(logn)
// mergin takes - 0(N) at worst case
// so O(nlogn) with log base 2 as divided by two

// space complextiy is O(N) as temp can have all n elem in worst case



// --------------------  QUICK SORT ----
// both in accending and decsnding order
// same TC as merge sort but no extara spcae - O(N)

// pick a pivot - and place it at it's correct postion in the array
// pivot can be any element 
// ex if arr[0] = 4; then arr[3] = 4 ;; at correct place


void quickSort(vector<int> arr, int low, int high) {
    if (low >= high) return;

    int pivot = low;
    int left = low;
    int right = high;

    while (left <= right) {
        if (arr[left] >= arr[pivot]) { // >= if pivot equal is found all >= to right and < at left
            if (arr[right] < arr[pivot]) {
                swap(arr[left], arr[right])
            } else right-- ;

        } else left++;
    }
    swap(arr[pivot], arr[left])

    quickSort(arr, low, left-1);
    quickSort(arr, left+1, high);
}

// striver code :::
int partition(vector<int> arr, int low , int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] < pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> arr, int low , int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

// TC - O(nlogn) 
// SC - O(1)
