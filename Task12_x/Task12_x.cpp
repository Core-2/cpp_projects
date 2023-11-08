#define Q_2

#ifdef Q_1 // Вопрос 1

#include <cmath>
#include <iostream>

class Point2d   // Вопрос 1a
{
private:
    double m_x{};
    double m_y{};

public:
    Point2d(double x = 0.0, double y = 0.0) :
        m_x{ x }, m_y{ y } {}

    void print() const
    {
        std::cout << "Point2d(" << this->m_x << ", " << this->m_y << ")\n";
    }

    //double distanceTo (const Point2d& point) const  // Вопрос 1b
    //{
    //    return std::sqrt((this->m_x - point.m_x) * (this->m_x - point.m_x) + 
    //                     (this->m_y - point.m_y) * (this->m_y - point.m_y));
    //}

    friend double distanceFrom(const Point2d&, const Point2d&);     // Вопрос 1c
};

double distanceFrom(const Point2d& point1, const Point2d& point2)   // Вопрос 1c
{
    return std::sqrt((point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) +
        (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: "
        << distanceFrom(first, second) << '\n';

    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <iostream>

class HelloWorld
{
private:
    char* m_data{};

public:
    HelloWorld()
    {
        m_data = new char[14];
        const char* init{ "Hello, World!" };
        for (int i = 0; i < 14; ++i)
            m_data[i] = init[i];
    }

    ~HelloWorld()
    {
        // замените этот комментарий своей реализацией деструктора
        delete[] m_data;
    }

    void print() const
    {
        std::cout << m_data << '\n';
    }

};

int main()
{
    HelloWorld hello{};
    hello.print();

    return 0;
}

#endif // Вопрос 2
