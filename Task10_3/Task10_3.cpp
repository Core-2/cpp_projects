#define Q_3

#ifdef Q_1 // Вопрос 1

#include <iostream>
#include <iterator>

int main()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int arraySize{ std::size(array) };

    for (int count{ 0 }; count < arraySize; ++count)
    {
        std::cout << array[count] << ' ';
    }
    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <iostream>
#include <iterator>

int getValue()
{
    while (true)
    {
        std::cout << "Enter a value from 1 to 9: ";
        int value{};
        std::cin >> value;

        if (std::cin.fail())
        {
            //сбрасываем все флаги ошибок
            std::cin.clear();
        }

        // игнорируем любые символы во входном буфере
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (value >= 1 && value <= 9)
        {
            return value;
        }
        else
        {
            std::cout << "You entered wrong value!\n";
        }
    }
}

int main()
{
    int value{ getValue() };

    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int arraySize{ std::size(array) };

    int index{};

    for (int count{ 0 }; count < arraySize; ++count)
    {
        std::cout << array[count] << ' ';

        if (value == array[count])
            index = count;
    }

    std::cout << "\nThe index of the value you entered is: " << index << '\n';
    return 0;
}

#endif // Вопрос 2



#ifdef Q_3 // Вопрос 3

#include <iostream>
#include <iterator> // для std::size

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };

    //int maxScore{ 0 };
    int maxIndex{ 0 };

    // теперь ищем максимальный результат во всем массиве
    for (unsigned int student{ 0 }; student < std::size(scores); ++student)
    {
        if (scores[student] > scores[maxIndex])
        {
            //maxScore = scores[student];
            maxIndex = student;
        }
    }

    //std::cout << "The best score was " << maxScore << '\n';
    std::cout << "The index of the best score is " << maxIndex << '\n';

    return 0;
}

#endif // Вопрос 3
