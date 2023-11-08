#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        if (m_numerator != 0 && m_denominator != 0)
        {
            int gcdInt{ Fraction::gcd(m_numerator, m_denominator) };
            m_numerator /= gcdInt;
            m_denominator /= gcdInt;
        }
    }

    Fraction(int a = 0, int b = 1)
        : m_numerator{ a }, m_denominator{ b }
    {
        this->reduce();
    }

    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, int b);
    friend Fraction operator*(int a, const Fraction& b);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);
};

Fraction operator*(const Fraction& a, const Fraction& b)
{
    return {a.m_numerator * b.m_numerator, 
        a.m_denominator * b.m_denominator};
}

Fraction operator*(const Fraction& a, int b)
{
    return { a.m_numerator * b,
        a.m_denominator };
}

Fraction operator*(int a, const Fraction& b)
{
    return { b * a };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}
std::istream& operator>>(std::istream& in, Fraction& f)
{
    in >> f.m_numerator;

    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

    in >> f.m_denominator;

    f.reduce();

    return in;
}

int main()
{
    Fraction f1{};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2{};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    // обратите внимание: результат f1 * f2 - это r-значение
    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    return 0;
}