#include <iostream>

int doubleNumber(int x)
{
    return x * 2;
}

int main()
{
    int value {};
    std::cin >> value;
    std::cout << value << " doubled is " << doubleNumber(value) << '\n';

    return 0;
}