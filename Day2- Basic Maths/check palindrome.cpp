// ------------------- Palindrom number
// ---------------------- 1
bool palindromNum(int n) {
    int cn = n; // created a copy of original n 
    int rev = 0;
    while (n > 0) { // reversing the number
        int lastDigit = n % 10;
        n /= 10;
        rev = rev * 10 + lastDigit;
    }
    if (cn == rev) return true;
    return false;
}
// this function do not check for overflow


// -------------------------- 2 - log approach
bool isPalindrome(int n) {
    if (n < 0) return false;        // negatives are not palindromes
    if (n >= 0 && n < 10) return true; // single-digit is palindrome

    int digits = (int)(log10(n)) + 1;
    int rev = 0;

    for (int i = 1; i <= digits / 2; i++) {
        int lastDigit = n % 10;
        n /= 10;
        rev = rev * 10 + lastDigit;
    }

    if (digits % 2 != 0) {
        n /= 10; // skip middle digit if odd number of digits 
    }

    return rev == n;
}
// uses more memory


// ------------------------- 3 - optimal approach
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false; 
    // negatives not palindrome
    // numbers ending in 0 (like 10, 100) can't be palindrome unless it's 0

    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    // if even digits → rev == x
    // if odd digits  → rev/10 == x (middle digit ignored)
    return (x == rev || x == rev / 10);
}

