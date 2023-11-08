#define Q_3

#ifdef Q_1 //Вопрос 1

#include <iostream>

int main()
{
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;


	if (num < 0)			//Исправление: добавлены фигурные скобки
	{
		std::cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}

	std::cout << "You entered: " << num;

	return 0;
}

#endif //Вопрос 1



#ifdef Q_2 //Вопрос 2

#include "constants.h"		//Создан заголовочный файл constants.h

#include <iostream>

int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

	return 0;
}

#endif //Вопрос 2



#ifdef Q_3 //Вопрос 3

#include <iostream>

bool passOrFail()
{
	////Мое решение:
	//static int count{ 0 };	//Создание статической переменной count
	//if (count < 3)			//Проверка count
	//{
	//	++count;			//Инкрементирует count
	//	return true;		//Функция возвращает true
	//}

	//return false;			//Когда функция отработала 3 раза, она начинает возвращать false

	//Предложенное решение:
	static int passes{ 3 };
	return (--passes >= 0);
}

int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';

	return 0;
}

#endif //Вопрос 3