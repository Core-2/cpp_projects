#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher
{
private:
	std::string m_name{};

public:
	Teacher(const std::string& name);

	const std::string& getName() const;
};

#endif // !TEACHER_H