#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer: ";
    int value{};
    std::cin >> value;
    return value;
}

void writeAnswer(int answer)
{
    std::cout << "Result is " << answer << '\n';
}