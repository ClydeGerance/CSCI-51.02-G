#include<iostream>

using namespace std;

int mult(int a, int b) {
    int prod = 0;
    bool neg = b < 0;
    b -= neg ? b+b : 0; // get absolute value
    while (b > 0) {
        if (b & 1) {
            if (neg)
                prod -= a;
            else
                prod += a;
        }
        a <<= 1;
        b >>= 1;
    }
    return prod;
}

int main(int argc, char* argv[]) {
    int x = stoi(argv[1]), y = stoi(argv[2]);
    cout << mult(x, y);
}