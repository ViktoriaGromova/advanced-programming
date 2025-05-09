#include <iostream>
#include "point.cpp"
#include "vector.cpp"

class Line
{
    int A;
    int B;
    int C;

public:
    Line(const Point &p1, const Point &p2) : A(p2.y - p1.y), B(p1.x - p2.x), C(-(A * p1.x + B * p1.y)) {}
    Line(const int angleCof, const int freeCof) : A(angleCof), B(-1), C(freeCof) {}
    Line(const Point &p, const int angleCof) : Line(angleCof, p.y - angleCof * p.x) {}
    bool isParallelLine(const Line &line) const;
    friend bool operator==(const Line &line1, const Line &line2);
};

bool Line::isParallelLine(const Line &line) const
{
    return vectorProductOnZ(Vector(A, B), Vector(line.A, line.B)) == 0;
}

bool operator==(const Line &line1, const Line &line2)
{
    return (line1.A * line2.B == line1.B * line2.A) &&
           (line1.A * line2.C == line1.C * line2.A) &&
           (line1.B * line2.C == line1.C * line2.B);
}

bool operator!=(const Line &line1, const Line &line2)
{
    return !(line1 == line2);
}