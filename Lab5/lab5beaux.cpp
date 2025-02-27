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
        
        Point3D points[N];
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y >> points[i].z;
        }
        for (int i = 1; i < N; i++) {
            cout << manhattan_distance(points[i-1], points[i]) << endl;
        }
        cout << endl;
    }
}