#include <iostream>
#include <cstring>
using namespace std;

void reverseString(const char* str) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        cout << "arg" << i << ": ";
        reverseString(argv[i]);
    }
    return 0;
}
