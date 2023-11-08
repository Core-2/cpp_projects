#include <iostream>
#include <cstddef>
#include <string>
#include <algorithm>
#include <limits>

std::size_t getLength()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t length{};
    std::cin >> length;

    return length;
}

void getNames(std::string* array, std::size_t length)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (std::size_t count{ 0 }; count < length; ++count)
    {
        std::cout << "Enter name #" << (count + 1) << ": ";
        std::getline(std::cin, array[count]);
    }
}

void printNames(std::string* array, std::size_t length)
{
    std::cout << "\nHere is your sorted list:\n";

    for (std::size_t count{ 0 }; count < length; ++count)
    {
        std::cout << "Name #" << (count + 1) << ": " << array[count] << '\n';
    }
}

int main()
{
    std::size_t arrayLength{getLength()};
    std::string* array{ new std::string[arrayLength]{} };

    getNames(array, arrayLength);

    std::sort(array, array + arrayLength);

    printNames(array, arrayLength);

    delete[] array;

    return 0;
}