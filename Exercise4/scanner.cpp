#include <cstdlib>
#include <iostream>
using namespace std;

int main(void) {
    int x;
    cout << "Enter an integer: ";
    cin >> x; // cin >> name; CSCI 51.02 ...
    cout << "Received input: " << x;
    cout << endl << "Added 2, now: ";
    cout << (x+2) << endl;
    return 0;
}

// What happens if you input a non-integer?

    // cin will not be able to parse the input as an integer. The following characters will also be considered as fail and it will output a 0

    // Enter an integer: b
    // Received input: 0
    // Added 2, now: 2

    // Enter an integer: ab13
    // Received input: 0
    // Added 2, now: 2

// Does it work for float variables?

    // It only accepts the numerical characters before the decimal point since "." is not consider an integer anymore.

    // Enter an integer: 13.2
    // Received input: 13
    // Added 2, now: 15