#include "point.cpp"
#include "line.cpp"

class Shape
{
    virtual int perimeter() = 0;
    virtual float area() = 0;
    virtual bool isSimilarTo(const Shape &another) = 0;
    virtual bool isCongruentTo(const Shape &another) = 0;
    virtual bool containsPoint(Point point) = 0;

    virtual void rotate(Point center, double angle) = 0;
    virtual void reflect(Point center) = 0;
    virtual void reflect(const Line &axis) = 0;
    virtual void scale(Point center, double coefficient) = 0;
};