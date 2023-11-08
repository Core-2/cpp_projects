#include <iostream>

bool isEven(int value)
{
    return (value % 2) == 0;
}

int main()
{
    std::cout << "Enter an integer: ";
    int value{};
    std::cin >> value;

    if (isEven(value))
        std::cout << value << " is even\n";
    else
        std::cout << value << " is odd\n";

    return 0;
}