#define Q_3

#ifdef Q_1 //Вопрос 1

#include <iostream>

int readNumber()								//Было: int readNumber(int x)
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
	int x{ readNumber() };						//Было: int x {};
												//Было: readNumber(x);
	x = x + readNumber();						//Было: x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}

#endif //Вопрос 1



#ifdef Q_2 //Вопрос 2

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
	int x{ readNumber() };						//Было: int x {};
	int y{ readNumber() };						//Было: int y {};
	//x = readNumber();
	//x = readNumber();
	writeAnswer(x / y);

	return 0;
}

#endif //Вопрос 2



#ifdef Q_3 //Вопрос 3

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

#endif //Вопрос 3