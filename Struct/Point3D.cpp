#include "Point3D.hpp"

// Default constructor (zero-initialized)
Point3D::Point3D() : x(0), y(0), z(0) {}

// Parameterized constructor
Point3D::Point3D(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal) {}

// Print function
void Point3D::printPoint() {
    std::cout << "Point3D: (" << x << ", " << y << ", " << z << ")\n";
}
