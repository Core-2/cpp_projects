#define Q_2

#ifdef Q_1 //Вопрос 1

#include <iostream>

int main()
{
    for (int even{ 0 }; even <= 20; even += 2)
        std::cout << even << ' ';

    return 0;
}

#endif //Вопрос 1



#ifdef Q_2 //Вопрос 2

#include <iostream>

int sumTo(int value)
{
    int result{ 0 };
    for (int count{ 1 }; count <= value; ++count)
        result += count;

    return result;
}

int main()
{
    std::cout << sumTo(5);
    return 0;
}

#endif //Вопрос 2