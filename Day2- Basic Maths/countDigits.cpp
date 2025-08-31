// Number of digits in a number

#include <iostream>
using namespace std;

// ---------- 1 -----------
// remove the last element by dividing the number by 10
// and increase the counter by 1 when you do so
int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        n/=10;
        count++;
    }
    return count;
}

// ---------- 2 ---------
// int rounds of the value ex. 3.56 -> 3;
// log gives one less no. of digits present so add 1
int countDigits2(int n) {
    int count = (int)(log10(n)) + 1;
    return count;
}

int main() {
    
    return 0;
}
