#include "department.h"
#include "teacher.h"
#include <iostream>

Department::Department()
{
}

Department::Department(const Teacher& teacher)
{
	add(teacher);
}

Department::~Department()
{
	std::cout << "\nDepartment was destructed!\n";
}

void Department::add(const Teacher& teacher)
{
	m_teachers.push_back(teacher);
}

std::ostream& operator<<(std::ostream& out, const Department& department)
{
	out << "Department: ";

	for (const auto& teacher : department.m_teachers)
		out << teacher.get().getName() << ' ';

	return out;
}