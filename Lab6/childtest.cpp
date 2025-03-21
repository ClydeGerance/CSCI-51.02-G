#include <iostream>
#include <unistd.h>

using namespace std;

int main(void){
    int i = 0;
    cout << "Hello!" << endl;
    i += 2;
    pid_t child = fork();
    i += 3;
    cout << i << endl;

    return 0;
}