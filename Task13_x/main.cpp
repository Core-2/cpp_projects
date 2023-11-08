#define Q_4

#ifdef Q_2 // Вопрос 2

#include <iostream>
#include <cstdint>

class Average
{
public:
    using intL32 = std::int_least32_t;
    using intL8 = std::int_least8_t;

private:
    intL32 m_sum{};
    intL8 m_count{};

public:
    Average() : m_sum{ 0 }, m_count{ 0 }
    {
    }

    Average& operator+=(int a)
    {
        m_sum += static_cast<intL32>(a);
        ++m_count;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
};

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
    out << (static_cast<double>(avg.m_sum) / avg.m_count);
    return out;
}

int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // два вызова объединены в цепочку
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}

#endif // Вопрос 2



#ifdef Q_3 // Вопрос 3

#include <cassert>
#include <iostream>

class IntArray
{
public:
    using size_type = unsigned int;

private:
    int* m_array{ nullptr };
    size_type m_size{ 0 };

public:
    IntArray(size_type size)
    {
        assert(size > 0 && "IntArray length should be a positive integer");
        m_array = new int[m_size] {};
    }

    IntArray(const IntArray& source)
    {
        deepCopy(source);
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    void deepCopy(const IntArray& source)
    {
        delete[] m_array;
        m_size = source.m_size;

        if (source.m_array)
        {
            m_array = new int[m_size];

            for (size_type i{ 0 }; i < m_size; ++i)
                m_array[i] = source.m_array[i];
        }
        else
            m_array = nullptr;
    }

    IntArray& operator=(const IntArray& source)
    {
        if (this != &source)
            deepCopy(source);

        return *this;
    }

    int& operator[](const size_type index)
    {
        assert(index >= 0);
        assert(index < m_size);
        return m_array[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);
};

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
    for (IntArray::size_type i{ 0 }; i < arr.m_size; ++i)
    {
        out << arr.m_array[i] << ' ';
    }

    return out;
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };
    std::cout << a << '\n';

    auto& ref{ a }; // используем эту ссылку, чтобы избежать
                    // ошибок компиляции, связанных с самоприсваиванием
    a = ref;

    IntArray b(1);
    b = a;

    std::cout << b << '\n';

    return 0;
}

#endif // Вопрос 3



#ifdef Q_4 // Вопрос 4

#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2
{
public:
    using int16_type = std::int_least16_t;
    using int8_type = std::int_least8_t;

private:
    int16_type m_whole{0};
    int8_type m_fraction{0};

public:
    FixedPoint2(int16_type whole = 0, int8_type fraction = 0)
        : m_whole{ whole }, m_fraction{ fraction }
    {
        assert(whole >= -32768 && whole <= 32767 && "FixedPoint2.whole number out of range.");
        assert(fraction >= -99 && fraction <= 99 && "FixedPoint2.fraction number out of range.");

        if (m_whole < 0 && m_fraction > 0)
            m_fraction = -m_fraction;

        if (m_whole > 0 && m_fraction < 0)
            m_whole = -m_whole;
    }

    FixedPoint2(double dValue):
        m_whole{ static_cast<int16_type>(std::round(dValue * 100) / 100) },
        m_fraction{ static_cast<int8_type>(std::round(dValue * 100) - m_whole * 100) }
    {
        //m_whole = static_cast<int16_type>(dValue);

        //dValue = (dValue - m_whole) * 100.0;

        //m_fraction = static_cast<int8_type>(dValue);

        //dValue = (dValue - m_fraction) * 10;
        //
        //if (dValue < 0.0)
        //    dValue = -dValue;

        //if (dValue > 5.0)
        //{
        //    if (m_fraction == 99)
        //    {
        //        ++m_whole;
        //        m_fraction = 0;
        //    }
        //    else if (m_fraction == -99)
        //    {
        //        --m_whole;
        //        m_fraction = 0;
        //    }
        //    else if (m_whole < 0 || m_fraction < 0)
        //        --m_fraction;
        //    else
        //        ++m_fraction;
        //}

        assert(m_whole >= -32768 && m_whole <= 32767 && "FixedPoint2.whole number out of range.");
        assert(m_fraction >= -99 && m_fraction <= 99 && "FixedPoint2.fraction number out of range.");
    }

    operator double() const
    {
        return static_cast<double>(m_fraction) / 100.0 + m_whole;
    }

    FixedPoint2 operator-() const
    {
        return FixedPoint2(-m_whole, -m_fraction);
    }

    friend FixedPoint2 operator+(const FixedPoint2& a, const FixedPoint2& b);
    friend bool operator==(const FixedPoint2& a, const FixedPoint2& b);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& value)
{
    out << static_cast<double>(value);
    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& value)
{
    double dIn{};
    in >> dIn;

    value = FixedPoint2(dIn);

    return in;
}

FixedPoint2 operator+(const FixedPoint2& a, const FixedPoint2& b)
{
    return FixedPoint2(static_cast<double>(a) + static_cast<double>(b));
}

bool operator==(const FixedPoint2& a, const FixedPoint2& b)
{
    return (a.m_whole == b.m_whole && a.m_fraction == b.m_fraction);
}

void testAddition()
{
    std::cout << std::boolalpha;
    // оба положительные, без переполнения дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n';
    // оба положительные, с переполнением дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n';
    // оба отрицательные, без переполнения дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n';
    // оба отрицательные, с переполнением дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n';
    // второе отрицательное, без переполнения дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n';
    // второе отрицательное, возможно переполнение дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n';
    // первое отрицательное, без переполнения дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n';
    // первое отрицательное, возможно переполнение дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n';
}

int main()
{
    testAddition();

    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // введите 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}

#endif // Вопрос 4
