#include<bits/stdc++.h>

using namespace std;

struct Point3D {
    int x, y, z;
};

int manhattan_distance(Point3D p1, Point3D p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}

int main() {
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        Point3D prev; 
        cin >> prev.x >> prev.y >> prev.z;

        for (int i = 1; i < N; i++) {
            Point3D curr; 
            cin >> curr.x >> curr.y >> curr.z;
            cout << manhattan_distance(prev, curr) << endl;
            prev = curr;
        }
        cout << endl;
    }
}