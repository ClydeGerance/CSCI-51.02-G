#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    for(int i = 0; i < argc; i++)
    {
        cout << "arg" << i << ": " << argv[i];
        cout << endl; // cout << "\n";
    }
    return 0; // non-zero means an error
}