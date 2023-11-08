#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int smaller{};                                  //smaller создается здесь
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};                                   //larger создается здесь
    std::cin >> larger;

    if (smaller > larger)
    {
        std::cout << "Swapping the values\n";
        int temp{ larger };                         //temp создается здесь
        larger = smaller;
        smaller = temp;
    }                                               //temp уничтожается здесь

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}                                                   //larger и smaller уничтожаются здесь