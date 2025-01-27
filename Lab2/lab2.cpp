#include<bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y; 
        string msg; 
        cin >> x >> y;
        getline(cin, msg);

        cout << "Agent#" << to_string(i+1) << " is at (" << x << ", " << y << ")" << endl << "Says:" << msg << endl; 
    }


    return 0;
}