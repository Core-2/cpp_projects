#define Q_2

#ifdef Q_1 // Вопрос 1

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student
{
    std::string name{};
    int grade{};
};

int main()
{
    std::array<Student, 8> arr{
        {   
            {"Albert", 3},
            {"Ben", 5},
            {"Christine", 2},
            {"Dan", 8},
            {"Enchilada", 4},
            {"Francis", 1},
            {"Greg", 3},
            {"Hagrid", 5}
        }
    };

    const auto bestStudent{std::max_element(arr.begin(), arr.end(),
                        [](Student& a, Student& b)
                        {
                            return (a.grade < b.grade);
                        }) };

    std::cout << bestStudent->name << " is the best student\n";
    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{
      { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    /*
     * Используйте здесь std::sort
     */
    std::sort(seasons.begin(), seasons.end(),
        [](const Season& a, const Season& b)
        {
            return (a.averageTemperature < b.averageTemperature);
        });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}

#endif // Вопрос 2
