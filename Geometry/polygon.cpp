#include "shape.cpp"

#include <vector>

class Polygon : public Shape
{
protected:
    std::vector<Point> vertices;

public:
    Polygon(const Point...);

    size_t verticesCount() const { return vertices.size(); }
    std::vector<Point> getVertices() const;
    bool isConvex();

    int perimeter() override {};
    float area() override {};

    

};