#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    signal(SIGCHLD, SIG_IGN);

    if (fork() == 0) { // child process

        cout << "Child PID: " << getpid() << endl;

        if (execl("/usr/bin/xclock", "myXclock", NULL) == -1) {
            cout << "Error: Couldn't run xclock." << endl;
        }

        
    } else { // parent

        cout << "Parent PID: " << getpid() << endl;

        int cnt = 0;
        while (true) {
            cnt++;
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "[%Y-%m-%d] %H:%M:%S", &datetime);
            cout << output << endl;

            if (cnt == 3) {
                cout << "“This program has gone on for far too long. Type Ctrl+C to abort this timer application.”" << endl;
                cnt = 0;
            }
        }
    }


    return 0;
}