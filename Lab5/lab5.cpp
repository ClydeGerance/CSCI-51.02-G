#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> points;

        // Read N points
        for (int n = 0; n < N; n++) {
            int x, y, z;
            cin >> x >> y >> z;
            points.push_back(make_tuple(x, y, z));
        }

        // Compute Manhattan distance
        for (int i = 0; i < N - 1; i++) {
            int x1, y1, z1, x2, y2, z2;
            tie(x1, y1, z1) = points[i];
            tie(x2, y2, z2) = points[i+1];

            int manhattan_distance = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
            cout << manhattan_distance << endl;
        }

        // Print a blank line after each test case (except the last one)
        if (t < T - 1) {
            cout << endl;
        }
    }

    return 0;
}
