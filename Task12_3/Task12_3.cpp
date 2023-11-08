#define Q_3

#ifdef Q_2 // Вопрос 2

#include <iostream>

class Point3d
{
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << '<' << m_x << ", " << m_y << ", " << m_z << ">\n";
    }

    bool isEqual(const Point3d& p)
    {
        return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
    }
};

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}

#endif // Вопрос 2



#ifdef Q_3 // Вопрос 3

#include <array>
#include <cassert>
#include <iostream>

class Stack
{
private:
    using arr_type = std::array<int, 10>;
    using size_type = arr_type::size_type;

    arr_type m_array{};
    size_type m_arrSize{ 0 };

public:
    void reset()
    {
        m_arrSize = 0;
    }

    bool push(int value)
    {
        if (m_arrSize == m_array.size())
            return false;

        m_array[m_arrSize++] = value;
        return true;
    }

    int pop()
    {
        assert(m_arrSize > 0 && "Can not pop empty stack");

        return m_array[--m_arrSize];
    }

    void print()
    {
        std::cout << "( ";

        for (size_type i{ 0 }; i < m_arrSize; ++i)
            std::cout << m_array[i] << ' ';

        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}

#endif // Вопрос 3
