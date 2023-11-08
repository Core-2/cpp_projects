#include <iostream>
#include <iterator>

int* find(int* begin, int* end, int value)
{
    while (begin != end)
    {
        if (*begin == value)
            return begin;

        ++begin;
    }
    return end;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Ищем первый элемент со значением 20.
    int* found{ find(std::begin(arr), std::end(arr), 20) };

    // Если найден элемент со значением 20, распечатываем его.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}