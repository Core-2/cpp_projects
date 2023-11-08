#include <iostream>

int getValue()
{
	std::cout << "Enter an integer: ";
	int value{};
	std::cin >> value;
	return value;
}

char getSign()
{
	std::cout << "Enter a sign (+, -, *, / or %): ";
	char sign{};
	std::cin >> sign;
	return sign;
}

int calculate(int x, int y, char sign)
{
	switch (sign)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		std::cout << "Error!\n";
		return 0;
	}
}

int main()
{
	int x{ getValue() };
	int y{ getValue() };

	char sign{ getSign() };

	std::cout << x << ' ' << sign << ' ' << y << " is " << calculate(x, y, sign) << '\n';

    return 0;
}