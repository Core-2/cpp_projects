//Вопрос 3
#include <iostream>

//Функция приема числа с плавающей точкой от пользователя
//и передачи его вызывающей функции:
double getNumber()
{
    std::cout << "Enter a double value: ";
    double value{};
    std::cin >> value;
    return value;
}

//Функция приема математического символа от пользователя
//и передачи его вызывающей функции:
char getSign()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char sign{};
    std::cin >> sign;
    return sign;
}

//Функция печати результата математического вычисления
//в консоль:
void writeAnswer(double x, double y, char sign)
{
    if (sign == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (sign == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (sign == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (sign == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
    double x{ getNumber() };
    double y{ getNumber() };

    char sign{ getSign() };

    writeAnswer(x, y, sign);
    return 0;
}