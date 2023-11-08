#include "teacher.h"
#include <string>

Teacher::Teacher(const std::string& name)
	: m_name{ name }
{
}

const std::string& Teacher::getName() const
{
	return m_name;
}