#define Q_4

#ifdef Q_1 // Вопрос 1

#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 30, 60, 20, 50, 40, 10 };
    constexpr int arraySize{ std::size(array) };

    std::cout << "Current array is:\n";
    for (int currentIndex{ 0 }; currentIndex < arraySize; ++currentIndex)
    {
        std::cout << array[currentIndex] << ' ';
    }

    for (int startIndex{ 0 }; startIndex < arraySize - 1; ++startIndex)
    {
        int smallestIndex{ startIndex };

        for (int currentIndex{ smallestIndex }; currentIndex < arraySize; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[smallestIndex]);

        std::cout << "\nIteration " << startIndex + 1 << ":\n";

        for (int currentIndex{ 0 }; currentIndex < arraySize; ++currentIndex)
        {
            std::cout << array[currentIndex] << ' ';
        }
    }
    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 30, 60, 20, 50, 40, 10 };
    constexpr int arraySize{ std::size(array) };

    std::cout << "Current array is:\n";
    for (int currentIndex{ 0 }; currentIndex < arraySize; ++currentIndex)
    {
        std::cout << array[currentIndex] << ' ';
    }

    for (int startIndex{ 0 }; startIndex < arraySize - 1; ++startIndex)
    {
        int biggestIndex{ startIndex };

        for (int currentIndex{ biggestIndex }; currentIndex < arraySize; ++currentIndex)
        {
            if (array[currentIndex] > array[biggestIndex])
                biggestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[biggestIndex]);

        std::cout << "\nIteration " << startIndex + 1 << ":\n";

        for (int currentIndex{ 0 }; currentIndex < arraySize; ++currentIndex)
        {
            std::cout << array[currentIndex] << ' ';
        }
    }
    return 0;
}

#endif // Вопрос 2



#ifdef Q_3 // Вопрос 3

#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int arraySize{ std::size(array) };

    for (int index{ 0 }; index < arraySize - 1; ++index)
    {
        for (int currentIndex{ 0 }; currentIndex < arraySize - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
                std::swap(array[currentIndex], array[currentIndex + 1]);
        }
    }

    for (int index{ 0 }; index < arraySize; ++index)
    {
        std::cout << array[index] << ' ';
    }

    return 0;
}

#endif // Вопрос 3



#ifdef Q_4 // Вопрос 4

#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int arraySize{ std::size(array) };

    for (int index{ 0 }; index < arraySize - 1; ++index)
    {
        bool isSwapped{ false };

        for (int currentIndex{ 0 }; currentIndex < arraySize - index - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped)
        {
            std::cout << "Early termination on iteration " << index + 1 << '\n';
            break;
        }
    }

    for (int index{ 0 }; index < arraySize; ++index)
    {
        std::cout << array[index] << ' ';
    }

    return 0;
}

#endif // Вопрос 4