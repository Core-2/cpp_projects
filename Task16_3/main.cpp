#include "department.h"
#include "teacher.h"
#include <iostream>

int main()
{
    // Создаем преподавателя вне области видимости факультета
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Создаем факультет и добавляем в него преподавателей
        Department department{}; // создаем пустой объект Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department здесь выходит из области видимости и уничтожается

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}