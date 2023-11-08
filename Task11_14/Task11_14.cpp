#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using list_type = std::vector<int>;

namespace parameters
{
    constexpr int randomMin{ 2 };
    constexpr int randomMax{ 4 };
    constexpr int guessDeviation{ 4 };
}

int getRandomNumber(int min, int max)
{
    std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    return std::uniform_int_distribution{ min, max }(mt);
}

int getValue()
{
    int value{};
    std::cin >> value;
    return value;
}

int getStart()
{
    std::cout << "Start where? ";
    return getValue();
}

int getNumbers()
{
    std::cout << "How many? ";
    return getValue();
}

void printCondition(int numbers, int randomNumber)
{
    std::cout << "I generated " << numbers << " square numbers. ";
    std::cout << "Do you know what each number is after multiplying it by " << randomNumber << "?\n";
}

list_type generateVector(int start, int nums, int rndm)
{
    list_type result(static_cast<list_type::size_type>(nums));

    for (auto& number : result)
    {
        number = start * start * rndm;
        ++start;
    }
    return result;
}

bool isNumberFound(int guess, list_type& numbers)
{
    auto found{ std::find(numbers.begin(), numbers.end(), guess) };

    if (found != numbers.end())
    {
        numbers.erase(found);
        return true;
    }  
    else
        return false;
}

void guessSucceed(list_type& numbers)
{
    std::cout << "Nice! ";
    if (numbers.size() == 0)
    {
        std::cout << "You found all numbers, good job!\n";
    }
    else
    {
        std::cout << numbers.size() << " numbers left.\n";
    }
}

int findClosestNumber(int guess, list_type& numbers)
{
    return *std::min_element(numbers.begin(), numbers.end(),
                [=](int a, int b)
                {
                    return (std::abs(a - guess) < std::abs(b - guess));
                });
}

void guessFailed(int guess, int closestNumber)
{
    std::cout << guess << " is wrong! ";

    if (std::abs(closestNumber - guess) <= parameters::guessDeviation)
    {
        std::cout << "Try " << closestNumber << " next time.\n";
    }
    else
        std::cout << '\n';
}

bool guessTheNumber(list_type& numbers)
{
    int guess{ getValue() };

    if (isNumberFound(guess, numbers))
    {
        guessSucceed(numbers);

        return !numbers.empty();
    }
    else
    {
        int closestNumber(findClosestNumber(guess, numbers));

        guessFailed(guess, closestNumber);

        return false;
    }
}

int main()
{
    int startValue{ getStart() };

    int numbers{ getNumbers() };

    int randomNumber{ getRandomNumber(parameters::randomMin, parameters::randomMax) };

    list_type generatedNumbers{generateVector(startValue, numbers, randomNumber)};

    printCondition(numbers, randomNumber);

    while (guessTheNumber(generatedNumbers))
        ;
    
    return 0;
}