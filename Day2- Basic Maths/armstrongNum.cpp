bool isArmstrong(int n) {
    int cn = n;
    int sum = 0;

    while (n > 0) {
        int lastDigit = n % 10;
        sum += lastDigit * lastDigit * lastDigit; // better than pow for int
        n /= 10;
    }

    return sum == cn;
}
