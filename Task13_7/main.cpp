#define Q_2

#ifdef Q_1 // Вопрос 1

#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
        : m_cents{ cents }
    {}

    friend bool operator> (const Cents& c1, const Cents& c2);
    friend bool operator<= (const Cents& c1, const Cents& c2);

    friend bool operator< (const Cents& c1, const Cents& c2);
    friend bool operator>= (const Cents& c1, const Cents& c2);
};

bool operator> (const Cents& c1, const Cents& c2)
{
    return c1.m_cents > c2.m_cents;
}

bool operator<= (const Cents& c1, const Cents& c2)
{
    return !(c1 > c2);
}

bool operator< (const Cents& c1, const Cents& c2)
{
    return c1.m_cents < c2.m_cents;
}

bool operator>= (const Cents& c1, const Cents& c2)
{
    return !(c1 < c2);
}

int main()
{
    Cents dime{ 10 };
    Cents nickel{ 5 };

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";
    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";
    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";
    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";


    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(const std::string& make, const std::string& model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator==(const Car& c1, const Car& c2);
    friend bool operator!=(const Car& c1, const Car& c2);

    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend bool operator<(const Car& c1, const Car& c2);
};

bool operator==(const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
        c1.m_model == c2.m_model);
}

bool operator!=(const Car& c1, const Car& c2)
{
    return !(c1 == c2);
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << '(' << car.m_make << ", " << car.m_model << ')';

    return out;
}

bool operator<(const Car& c1, const Car& c2)
{
    if (c1.m_make == c2.m_make)
        return c1.m_model < c2.m_model;
    else
        return c1.m_make < c2.m_make;
}

int main()
{
    std::vector<Car> cars{
      { "Toyota", "Corolla" },
      { "Honda", "Accord" },
      { "Toyota", "Camry" },
      { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // требуется перегруженный operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // требуется перегруженный operator<<

    return 0;
}

#endif // Вопрос 2
