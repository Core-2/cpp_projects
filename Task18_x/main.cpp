#include <algorithm>
#include <iostream>
#include <vector>

class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};

class Point
{
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    Point(int x = 0, int y = 0, int z = 0) :
        m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
    }
};

class Triangle : public Shape
{
private:
    Point m_point1{};
    Point m_point2{};
    Point m_point3{};

public:
    Triangle(const Point& point1, const Point& point2, const Point& point3) :
        m_point1{ point1 }, m_point2{ point2 }, m_point3{ point3 }
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle("
            << m_point1 << ", "
            << m_point2 << ", "
            << m_point3 << ')';

        return out;
    }
};

class Circle : public Shape
{
private:
    Point m_center{};
    int m_radius{};

public:
    Circle(const Point& center, int radius) :
        m_center{ center }, m_radius{ radius }
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", radius " << m_radius << ')';

        return out;
    }

    int getRadius() const { return m_radius; }
};

int getLargestRadius(const std::vector<Shape*>& shapes)
{
    int largestRadius{ 0 };

    for (const auto* shape : shapes)
    {
        if (auto * circle{ dynamic_cast<const Circle*>(shape) })
        {
            largestRadius = std::max(largestRadius, circle->getRadius());
        }
    }

    return largestRadius;
}

int main()
{
    std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    // здесь удаляем каждый элемент вектора

    for (const auto* element : v)
    {
        delete element;
    }

    return 0;
}