#include <iostream> // For cout
#include <cstdio>   // For printf
using namespace std;

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        // Print the first character of each argument
        printf("%c\n", argv[i][0]);

        // Print the rest of the argument (starting from the second character)
        printf("%s\n", argv[i] + 1);
    }
    return 0;
}
