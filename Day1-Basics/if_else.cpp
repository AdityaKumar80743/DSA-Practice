// program to under stand conditional statements
// program to print odd even numbers

#include <iostream>
using namespace std;

int main() {
    cout << "Programe to check Odd Even number" << endl;
    int num;
    cout << "Enter a number to check: ";
    cin >> num;
    
    // if reminder to any number when divided by two is zero it is a even number 
    // if not it is a odd number
    if (num % 2 == 0) {
        cout << num << " is even" << endl;
    } else {
        cout << num << " is odd" << endl;
    }
}
