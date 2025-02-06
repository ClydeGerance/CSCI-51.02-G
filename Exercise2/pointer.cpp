#include <iostream>
using namespace std;

int main(void) {

    int i;
    int *p;
    p = &i;
    i = 5;

    cout << "int i = "<< i << endl;
    cout << "pointer p: " << p << endl;
    cout << "address of i: " << &i<< endl;
    cout << "dereference p: " << *p << endl;
}