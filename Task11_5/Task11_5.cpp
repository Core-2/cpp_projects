#include <iostream>
#include <string>
#include <utility>
#include <vector>

int sumTo(int x)
{
    int sum{ 0 };
    for (int i{ 1 }; i <= x; ++i)
        sum += i;

    return sum;
}

struct Employee
{
    std::string name{};
};

void printEmployeeName(const Employee& employee)
{
    std::cout << employee.name << '\n';
}

std::pair<int, int> minmax(int x, int y)
{
    if (x < y)
        return { x , y };
    else
        return { y , x };
}

using index_type = std::vector<int>::size_type;

index_type getIndexOfLargestValue(const std::vector<int>& values)
{
    index_type index{ 0 };
    int maxValue{ 0 };

    for (index_type i{ 0 }; i < values.size(); ++i)
    {
        if (values[i] > maxValue)
        {
            maxValue = values[i];
            index = i;
        }
    }

    return index;
}

const std::string& getElement(const std::vector<std::string>& strings, index_type index)
{
    return strings[index];
}

int main()
{
    std::cout << sumTo(6) << '\n';

    Employee joe{ "Joe" };
    printEmployeeName(joe);

    auto [a, b] {minmax(6, 2)};
    std::cout << a << " < " << b << '\n';

    std::vector<int> values{ 4, 6, 12, 3, 8, 1 };
    std::cout << getIndexOfLargestValue(values) << '\n';

    std::vector<std::string> strings{"Joe", "Nick", "Alex"};
    std::cout << getElement(strings, 1) << '\n';
    return 0;
}