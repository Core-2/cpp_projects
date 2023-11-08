#define Q_4

#ifdef Q_2 //Вопрос 2

#include <iostream>

int main()
{
    char letter{'a'};
    while (letter <= 'z')
    {
        std::cout << letter << " - " << static_cast<int>(letter) << '\n';
        ++letter;
    }

    return 0;
}

#endif //Вопрос 2



#ifdef Q_3 //Вопрос 3

#include <iostream>

int main()
{
    int outer{ 5 };
    while (outer >= 1)
    {
        int inner{ 0 };
        while (inner < outer)
        {
            std::cout << outer - inner << ' ';
            ++inner;
        }
        std::cout << '\n';
        --outer;
    }

    return 0;
}

#endif //Вопрос 3



#ifdef Q_4 //Вопрос 4

#include <iostream>

int main()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int inner{ 5 };
        while (inner >= 1)
        {
            if (inner <= outer)
            {
                std::cout << inner << ' ';
            }
            else
            {
                std::cout << ' ' << ' ';
            }
            --inner;
        }
        std::cout << '\n';
        ++outer;
    }

    return 0;
}

#endif //Вопрос 4