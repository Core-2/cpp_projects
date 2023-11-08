#define Q_4

#ifdef Q_1 // Вопрос 1

#include <iostream>

int factorial(int n)
{
    if (n <= 0)
        return 1;

    return (n * factorial(n - 1));
}

int main()
{
    std::cout << "Enter an integer: ";
    int fac{};
    std::cin >> fac;
    for (int count{ 0 }; count <= fac; ++count)
        std::cout << count << "! = " << factorial(count) << '\n';

    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <iostream>

int sumDigits(int value)
{
    if (value < 10)
        return value;

    return ((value % 10) + sumDigits(value / 10));
}

int main()
{
    std::cout << "Enter an integer: ";
    int value{};
    std::cin >> value;

    std::cout << "Sum of the digits is: " << sumDigits(value) << '\n';
    return 0;
}

#endif // Вопрос 2



#ifdef Q_3 // Вопрос 3

#include <iostream>

void convertToBinary(int value)
{
    if (value > 1)
        convertToBinary(value / 2);

    std::cout << value % 2;
}

int main()
{
    std::cout << "Enter positive integer: ";
    int value{};
    std::cin >> value;

    convertToBinary(value);
    return 0;
}

#endif // Вопрос 3



#ifdef Q_4 // Вопрос 4

#include <iostream>

void convertToBinary(unsigned int value)
{
    if (value > 1)
        convertToBinary(value / 2);

    std::cout << value % 2;
}

int main()
{
    std::cout << "Enter positive integer: ";
    int value{};
    std::cin >> value;

    convertToBinary(static_cast<unsigned int>(value));
    return 0;
}

#endif // Вопрос 4
