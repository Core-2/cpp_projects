#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "teacher.h"
#include <functional>
#include <iostream>
#include <vector>

class Department
{
public:
	using strVector = std::vector<std::reference_wrapper<const Teacher>>;
private:
	strVector m_teachers{};

public:
	Department();
	Department(const Teacher& teacher);
	~Department();

	void add(const Teacher& teacher);

	friend std::ostream& operator<<(std::ostream& out, const Department& department);
};

#endif // !DEPARTMENT_H