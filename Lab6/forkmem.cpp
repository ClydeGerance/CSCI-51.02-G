#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        cout << "👶 Child PID: " << getpid() << endl;
    } else {
        cout << "👨 Parent PID: " << getpid() << endl;
    }

    sleep(60); // So we can inspect their memory before they exit
    return 0;
}
