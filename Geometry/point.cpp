class Point
{
public:
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(const int x, const int y) : x(x), y(y) {}
    Point& operator-=(const Point& p);
};

Point &Point::operator-=(const Point &p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

Point operator-(const Point &p1, const Point &p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}

bool operator==(const Point &p1, const Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point &p1, const Point p2)
{
    return !(p1 == p2);
}