#include <iostream>

int getValue()
{
    std::cout << "Enter value from 0 to 255: ";
    int value{};
    std::cin >> value;
    return value;
}

int decToBin(int value, int pow)
{
    if (value >= pow)
        std::cout << '1';
    else
        std::cout << '0';

    return (value >= pow ? value - pow : value);
}

int main()
{
    int value{ getValue() };
    if (value < 0 || value > 255)
        return 0;

    value = decToBin(value, 128);
    value = decToBin(value, 64);
    value = decToBin(value, 32);
    value = decToBin(value, 16);

    std::cout << ' ';

    value = decToBin(value, 8);
    value = decToBin(value, 4);
    value = decToBin(value, 2);
    value = decToBin(value, 1);

    return 0;
}