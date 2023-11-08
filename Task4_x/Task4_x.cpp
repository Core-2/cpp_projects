//������ 3
#include <iostream>

//������� ������ ����� � ��������� ������ �� ������������
//� �������� ��� ���������� �������:
double getNumber()
{
    std::cout << "Enter a double value: ";
    double value{};
    std::cin >> value;
    return value;
}

//������� ������ ��������������� ������� �� ������������
//� �������� ��� ���������� �������:
char getSign()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char sign{};
    std::cin >> sign;
    return sign;
}

//������� ������ ���������� ��������������� ����������
//� �������:
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