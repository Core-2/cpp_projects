#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](const std::string& name);
};

char& GradeMap::operator[](const std::string& name)
{
    auto result{ std::find_if(m_map.begin(), m_map.end(), 
        [&](const auto& student) {
            return (student.name == name);
        }) };

    if (result != m_map.end())
        return result->grade;
    else
    {
        m_map.push_back({ name });
        return m_map.back().grade;
    }
}

int main()
{
    GradeMap grades{};

    char& gradeJoe{ grades["Joe"] };     // выполняет push_back
    gradeJoe = 'A';

    char& gradeFrank{ grades["Frank"] }; // выполняет push_back
    gradeFrank = 'B';

    std::cout << "Joe has a grade of " << gradeJoe << '\n';
    std::cout << "Frank has a grade of " << gradeFrank << '\n';

    return 0;
}