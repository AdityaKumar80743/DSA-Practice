// print divisors
// ------ 1 
// slow for large values
// time complexity - O(N)
// print all divisors in ascending order naturally
void divisors(int n) {
    // loop half as second last divisor can't be greater than n / 2
    for (int i=1; i<=n/2; i++) {
        if (n%i == 0) {
            cout << i << " ";
        }
    }
    cout << n << endl;
}

// ---------------- 2
void divisors2(int n) {
    vector<int> bigDivisors;

    for (int i=1; i*i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";  // smaller divisor
            if (i != n / i) bigDivisors.push_back(n / i); // store bigger divisor
        }
    }

    // print stored divisors in reverse to keep ascending order
    for (int i = bigDivisors.size() - 1; i >= 0; i--) {
        cout << bigDivisors[i] << " ";
    }
    cout << endl;
}
