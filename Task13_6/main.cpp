#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) :
        m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    // Преобразует Point в отрицательный эквивалент
    Point operator- () const;

    // Преобразует Point в положительный эквивалент
    Point operator+ () const;

    // Возвращает true, если точка установлена ​​в начале координат
    bool operator! () const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

// Преобразует Point в отрицательный эквивалент
Point Point::operator- () const
{
    return Point(-m_x, -m_y, -m_z);
}

// Преобразует Point в положительный эквивалент
Point Point::operator+ () const
{
    return *this;
}

// Возвращает true, если точка установлена ​​в начале координат, иначе false
bool Point::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{
    // использовать конструктор по умолчанию для установки в (0.0, 0.0, 0.0)
    Point point{};

    if (!point)
        std::cout << "point is set at the origin.\n";
    else
        std::cout << "point is not set at the origin.\n";

    Point p1{ -3.0, -2.5, -6.25 };
    Point p2{ +p1 };
    std::cout << p2.getX() << ' ' << p2.getY() << ' ' << p2.getZ() << '\n';

    return 0;
}