#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <iostream>

struct Point3D {
    int x, y, z;

    // Constructor
    Point3D();
    Point3D(int xVal, int yVal, int zVal);

    // Display function
    void printPoint();
};

#endif
