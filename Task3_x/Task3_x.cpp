#define Q_3

#ifdef Q_1 //������ 1

#include <iostream>

int readNumber()								//����: int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x;
}

int main()
{
	int x{ readNumber() };						//����: int x {};
												//����: readNumber(x);
	x = x + readNumber();						//����: x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}

#endif //������ 1



#ifdef Q_2 //������ 2

#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number:";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The quotient is: " << x;
}

int main()
{
	int x{ readNumber() };						//����: int x {};
	int y{ readNumber() };						//����: int y {};
	//x = readNumber();
	//x = readNumber();
	writeAnswer(x / y);

	return 0;
}

#endif //������ 2



#ifdef Q_3 //������ 3

#include <iostream>

void d()
{ // call stack: main() -> a() -> b() -> d()
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}

#endif //������ 3