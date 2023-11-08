#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

constexpr int max_number{2000000000};   // a number, before which numbers can be converted
constexpr int decimal{ 10 };
constexpr int hundred{ 100 };
constexpr int thousand{ 1000 };

// a container std::map with all possible verbal expressions of numbers:
static std::map<int, std::string> digitStr
{
    { 0, "" }, {1, "����" }, {2,  "���" }, { 3, "���" }, {4, "������" },
    { 5, "����" }, {6, "�����" }, {7,  "����" }, { 8, "������" }, {9, "������" },
    { 10, "������" }, {11, "�����������" }, {12,  "����������" }, { 13, "����������" }, {14, "������������" },
    { 15, "����������" }, {16, "�����������" }, {17,  "����������" }, { 18, "������������" }, {19, "������������" },
    { 20, "��������" }, {30, "��������" }, {40,  "�����" }, { 5080, "�����" }, {90,  "���������" },
    { 100, "���" }, {200, "������" }, { 300, "������" }, {400, "���������" }, {500'900,  "���" },
    { 1000, "������" }, { 2000, "������" }, { 5000, "�����" }, { 1'000'000, "�������" }, { 2'000'000, "��������" },
    { 5'000'000, "���������" }, { 1'000'000'000, "��������" }, { 201, "����" }, { 202, "���" }
};

// a function that converts digits (maximum hundreds) to strings:
std::string digitsToStr(int number, int index)
{
    assert(number >= 0 && number < thousand);

    std::string result{};

    int temp{ number - (number % hundred) };

    if (temp >= 100 && temp <= 400)
        result += digitStr[temp] + ' ';

    if (temp >= 500 && temp <= 900)
        result += digitStr[temp / hundred] + digitStr[500'900] + ' ';

    temp = number % hundred;

    if (temp >= 10 && temp <= 19)
    {
        result += digitStr[temp] + ' ';
        return result;
    }

    temp -= temp % decimal;

    if (temp >= 20 && temp <= 40 || temp == 90)
        result += digitStr[temp] + ' ';

    if (temp >= 50 && temp <= 80)
        result += digitStr[temp / decimal] + digitStr[5080] + ' ';

    temp = number % decimal;

    if ((temp == 1 || temp == 2) && index == 1)
        result += digitStr[200 + temp] + ' ';
    else
        result += digitStr[temp];

    if (temp != 0)
        result += ' ';

    return result;
}

// a function that converts number base (thousands, millions, etc.) to strings: 
std::string baseToStr(int number, int index)
{
    if (number == 0)
        return "";

    number %= hundred;

    switch (index)
    {
    case 0:
        return "";
    case 1:
        if (number < 10 || number > 19)
        {
            int digit{ number % decimal };

            if (digit == 1)
                return digitStr[1000] + ' ';

            if (digit >= 2 && digit <= 4)
                return digitStr[2000] + ' ';
            else
                return digitStr[5000] + ' ';
        }
        else
            return digitStr[5000] + ' ';
    case 2:
        if (number < 10 || number > 19)
        {
            int digit{ number % decimal };

            if (digit == 1)
                return digitStr[1'000'000] + ' ';

            if (digit >= 2 && digit <= 4)
                return digitStr[2'000'000] + ' ';
            else
                return digitStr[5'000'000] + ' ';
        }
        else
            return digitStr[5'000'000] + ' ';
    case 3:
        return digitStr[1'000'000'000] + ' ';
    default:
        return "ERROR";
    }
}

// a function that completely converts a number into a verbal expression:
std::string convertToStr(int number)
{
    assert(number > 0 && number < max_number);

    std::vector<int> v{};
    do
    {
        v.push_back(number % thousand);
        number /= thousand;
    } while (number != 0);

    std::string result{};

    for (int i{ static_cast<int>(v.size()) - 1 }; i >= 0; --i)
    {
        result += digitsToStr(v[i], i) + baseToStr(v[i], i);
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "");

    std::cout << convertToStr(230'000'000) << "������.\n";
    
    return 0;
}