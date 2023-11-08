#define Q_2

#ifdef Q_1 // Вопрос 1

#include <iostream>

struct Advertising
{
    int showedAds{};
    double clickedPercentage{};
    double avgWage{};
};

Advertising getAdsStats()
{
    Advertising result{};
    std::cout << "How many times ads were shown today? ";
    std::cin >> result.showedAds;

    std::cout << "What is the percentage of clicked ads? ";
    std::cin >> result.clickedPercentage;

    std::cout << "How much is your average wage from clicked ad? ";
    std::cin >> result.avgWage;

    return result;
}

void printAdvertising(Advertising ads)
{
    std::cout << "\nAds showed: " << ads.showedAds << " times\n";
    std::cout << "Ads clicked percentage: " << ads.clickedPercentage << "%\n";
    std::cout << "Average wage from click: $" << ads.avgWage << '\n';
    std::cout << "\nToday you earned: $" << ads.showedAds * (ads.clickedPercentage / 100.0) * ads.avgWage << '\n';
}

int main()
{
    Advertising ads{ getAdsStats() };
    printAdvertising(ads);
    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <iostream>

struct Fraction
{
    int numerator{};
    int denominator{};
};

Fraction getFraction()
{
    Fraction result{};
    std::cout << "Enter a numerator: ";
    std::cin >> result.numerator;

    std::cout << "Enter a denominator: ";
    std::cin >> result.denominator;

    return result;
}

double multiply(Fraction x, Fraction y)
{
    double multipliedNum{static_cast<double>(x.numerator) * y.numerator};
    double multipliedDenom{ static_cast<double>(x.denominator) * y.denominator};

    return multipliedNum / multipliedDenom;
}

int main()
{
    std::cout << "Enter first fraction:\n";
    Fraction fr1{ getFraction() };

    std::cout << "Enter second fraction:\n";
    Fraction fr2{ getFraction() };

    std::cout << fr1.numerator << '/' << fr1.denominator << " * ";
    std::cout << fr2.numerator << '/' << fr2.denominator << " is ";
    std::cout << multiply(fr1, fr2) << '\n';

    return 0;
}

#endif // Вопрос 2
