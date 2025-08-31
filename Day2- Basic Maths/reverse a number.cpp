// Reverse a Number
// tailing zeros are not inclued when reversed

int reverseNum(int n) {
    int rev = 0;
    while (n > 0) {
        int lastDigit = n % 10; // extracting the last digit
        n /= 10; // removing the last element
        rev = rev * 10 + lastDigit;
    }
    return rev;
}
