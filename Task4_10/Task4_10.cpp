//Вопрос 1
#include <iostream>

int main()
{
    std::cout << "Enter prime number: ";
    int x{};
    std::cin >> x;

    if (x == 2 || x == 3 || x == 5 || x == 7)
        std::cout << "The digit is prime";
    else
        std::cout << "The digit is not prime";
    return 0;
}