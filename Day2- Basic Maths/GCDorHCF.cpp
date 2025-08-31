// GCD
// ------------------------ 1 - brute force
int gcd(int n1, int n2) {
    int res = 1;
    for (int i=2; i<= min(n1,n2); i++) {
        if (n1 % i == 0 && n2%i == 0) {
            res = i;
        }
    }
    return res;
}


// -------------- 2 - optimal approach
// can go in reverese check to avoid extra ( int gcd);
// but time completixty of worst case will be same

// =-------------  EUCLIDENA ALGORITHM
int gcd2(int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1> n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }
    if (n1 ==0) return n2;
    return n1;

}
// as gcd(a,b) = gcd(a-b, b) - in end where a = 0 -> b = gcd
// instead of subtracing b times use modules of (b)
