#define Q_1c

#ifdef Q_1ab    // Вопрос 1a-1b

#include <iostream>

class Vector3d;     // Вопрос 1b

class Point3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    void print() const
    {
        std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void moveByVector(const Vector3d& v);   // Вопрос 1b

    //void moveByVector(const Vector3d& v)
    //{
    //    // реализуйте эту функцию как друг класса Vector3d
    //    m_x += v.m_x;
    //    m_y += v.m_y;
    //    m_z += v.m_z;
    //}
};

class Vector3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    void print() const
    {
        std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    //// Вопрос 1a
    //friend class Point3d;

    // Вопрос 1b
    friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector(const Vector3d& v)   // Вопрос 1b
{
    // реализуйте эту функцию как друг класса Vector3d
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

int main()
{
    Point3d p{ 1.0, 2.0, 3.0 };
    Vector3d v{ 2.0, 2.0, -3.0 };

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}

#endif // Вопрос 1a-1b



#ifdef Q_1c // Вопрос 1c

#include "Point3d.h"
#include "Vector3d.h"

int main()
{
    Point3d p{ 1.0, 2.0, 3.0 };
    Vector3d v{ 2.0, 2.0, -3.0 };

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}

#endif // Вопрос 1c
