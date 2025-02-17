#include <iostream>
#include "Point3D.hpp"

int main() {
    // Creating an instance
    Point3D p;
    Point3D* q;

    // Assign values manually
    p.x = 5;
    p.y = -2;
    p.z = 999;

    // Print values
    std::cout << "Initial p values:\n";
    p.printPoint();

    // Pointer manipulation
    q = &p;
    q->x = 1000; // same as (*q).x

    std::cout << "After modifying via pointer:\n";
    p.printPoint();

    // Using constructor
    Point3D point(1, 2, 3);
    std::cout << "Constructor initialized values:\n";
    point.printPoint();

    // Default constructor instance
    Point3D orig;
    std::cout << "Default initialized values:\n";
    orig.printPoint();

    return 0;
}
