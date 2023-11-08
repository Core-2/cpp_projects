#define Q_1

#ifdef Q_1 //Вопрос 1

#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
    double heightNow{ initialHeight - distanceFallen };

    // Проверяем, не ушли ли мы под землю
    // Если это так, устанавливаем высоту на уровне земли
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight)
{
    int time{ 0 };
    while (true)
    {
        std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";

        if (!calculateHeight(initialHeight, time))
            break;

        ++time;
    }
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight);

    return 0;
}

#endif //Вопрос 1



#ifdef Q_2 //Вопрос 2

#include <iostream>
#include <cassert>

bool isPrime(int x)
{
    // напишите эту функцию с помощью цикла for
    int dividers{ 1 };
    for (int count{ 2 }; count <= x; ++count)
    {
        if (x % count == 0)
            ++dividers;
    }

    return (dividers == 2);
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!";

    return 0;
}

#endif //Вопрос 2