#include<iostream>

using namespace std;

int mult(int a, int b) {
    int prod = 0;
    bool neg = (a < 0) ^ (b < 0);

    a = abs(a);     // get absolute value
    b = abs(b);

    while (b > 0) {
        if (b & 1) 
            prod+=a;
        
        a <<= 1;
        b >>= 1;
    }
    return neg ? -prod: prod;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << a << " * " << b << " = " << mult(a, b) << endl;
    return 0;
}