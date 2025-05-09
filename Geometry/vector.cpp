#include <iostream>

class Vector
{
public:
    int x;
    int y;

    Vector() : x(0), y(0) {}
    Vector(const int x, const int y) : x(x), y(y) {}
};

int scalarProduct(const Vector &v1, const Vector &v2){
    return v1.x * v2.x + v1.y * v2.y;
}

int vectorProductOnZ(const Vector &v1, const Vector &v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}