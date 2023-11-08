#include <string>
#include <iostream>

class Ball
{
private:
	std::string m_color{ "black" };
	double m_radius;

public:

	// Конструктор только с параметром радиуса
	// (цвет будет использовать значение по умолчанию)
	Ball(double radius) : m_radius{ radius }
	{
	}

	// Конструктор с параметрами и цвета, и радиуса
	Ball(const std::string& color = "black", double radius = 10.0) :
		m_color{ color }, m_radius{ radius }
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}