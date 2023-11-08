#include "department.h"
#include "teacher.h"
#include <iostream>

int main()
{
    // ������� ������������� ��� ������� ��������� ����������
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // ������� ��������� � ��������� � ���� ��������������
        Department department{}; // ������� ������ ������ Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department ����� ������� �� ������� ��������� � ������������

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}