#include <iostream>
#include <unistd.h>
#include <ctime>
#include <iomanip>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (pid == 0) {
        char *args[] = {
            (char *)"myXclock", 
            nullptr
        };

        execv("/usr/bin/xclock", args);

        cerr << "Failed to exec xclock" << endl;
        return 1;
    } else {
        int counter = 0;

        while (true) {
            time_t now = time(nullptr);
            struct tm *timeinfo = localtime(&now);

            cout << "["
                 << (timeinfo->tm_year + 1900) << "-"
                 << setfill('0') << setw(2) << (timeinfo->tm_mon + 1) << "-"
                 << setw(2) << timeinfo->tm_mday << "] "
                 << setw(2) << timeinfo->tm_hour << ":"
                 << setw(2) << timeinfo->tm_min << ":"
                 << setw(2) << timeinfo->tm_sec
                 << endl;

            counter++;

            if (counter % 3 == 0) {
                cout << "\"This program has gone on for far too long. Type Ctrl+C to abort this timer application.\"" << endl;
            }

            sleep(10);
        }
    }

    return 0;
}
