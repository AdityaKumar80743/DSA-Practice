// left rotate a array by one place
void leftRotate(vector<int> arr, int n) {
    int temp = arr[0];
    for (int i=0; i<=n-2; i++) {
        arr[i] = arr[i+1];      
    }
    arr[n-1] = temp;
    print(arr, n);
}
    
// to solve the above problem we are using O(1) extra space - but for solving the problem whole we are taking O(N) space -- size of the arr   
// Always specify the SC - extra spcae or - space taken to solve the problem
    
    
// Left rotate the array by D places
// brute force 
void leftRotateD(vector<int> arr, int n, int d) {
    d = d % n; // optimisation d will not be > than n
    for (int i=0; i<d; i++) {
        int temp = arr[0];
        for (int j=0; j<=n-2; j++) {
            arr[j] = arr[j+1];
        }
        arr[n-1] = temp;
    }
    print(arr, n);
}

// better
void leftRotateD2(vector<int> arr, int n, int d) {
    d = d % n;
    
    vector<int> temp; 
    for (int i=0; i<d; i++) {
        temp.push_back(arr[i]);       
    }
    
    for (int i=d; i<n; i++) {
        arr[i-d] = arr[i];
    }
    
    for (int i=n-d; i<n; i++) {
        arr[i] = temp[i - (n-d)];
    }
    
    print(arr, n);
}

// optimal
void reverse1(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void leftRotateD3(vector<int> arr, int n, int d) {
    reverse(arr.begin(), arr.begin()+d); // part that will be on right after rotation
    reverse(arr.begin()+d, arr.end()); // part that will be on left
    reverse(arr.begin(), arr.end()); // reverse the while array
    
    print(arr, n);
}

// TC - O(2n) - O(N)
// SC - O(1)
// make costom function to reverse if not to use stl;


// Move all the zeros to end of the array
// brute force -
// sort and reverse
