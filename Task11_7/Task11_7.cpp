#include <iostream>
#include <functional>

int getValue()
{
    std::cout << "Enter an integer: ";
    int value{};
    std::cin >> value;
    return value;
}

char getOperator()
{ 
    char op{};
    
    do
    {
        std::cout << "Enter an operator (+, -, * or /): ";
        std::cin >> op;

        if (std::cin.fail())
            std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    default:
    case '+': return &add;
    case '-': return &subtract;
    case '*': return &multiply;
    case '/': return &division;
    }
}

int main()
{
    int x{ getValue() };
    char op{ getOperator() };
    int y{ getValue() };

    ArithmeticFunction arFcn{ getArithmeticFunction(op) };

    std::cout << x << ' ' << op << ' ' << y << " = " << arFcn(x, y) << '\n';
    return 0;
}