// Reverse a Number
// tailing zeros are not inclued when reversed

// work for only positve numbers

int reverseNum(int n) {
    int rev = 0;
    while (n > 0) {
        int lastDigit = n % 10; // extracting the last digit
        n /= 10; // removing the last element
        rev = rev * 10 + lastDigit;
    }
    return rev;
}

// --------------------------------------------------
// work for all real numbers

int reverse(int x) {
    long long rev = 0;  // prevent overflow
    bool isNegative = x < 0;
    long long n = abs((long long)x); // converts negative to positive

    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    if (rev > INT_MAX) return 0;  // check for overflow
    return isNegative ? -rev : rev;
}

// ------------------------------------------------------
// optimal solution

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // check for overflow before actually multiplying
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }
    return rev;
}

// why to check if digit > 7 and digit < -8
// this is due to :
// INT_MIN = -2147483648   (-2^31)
// INT_MAX =  2147483647   ( 2^31 - 1)
// if the digit is greater than then the INT_MAX and greater than last digit of INT_MAX then rev - overflows
// to handle overflow return



