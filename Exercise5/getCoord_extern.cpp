#include <iostream>
using namespace std;
#EXTERN
struct Point3D{
    int x;
    int y;
    int z;
};

extern int getCoord(Point3D p);

extern int main(void);
