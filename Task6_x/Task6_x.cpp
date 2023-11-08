#define Q_3

#ifdef Q_1 //������ 1

#include <iostream>

int main()
{
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;


	if (num < 0)			//�����������: ��������� �������� ������
	{
		std::cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}

	std::cout << "You entered: " << num;

	return 0;
}

#endif //������ 1



#ifdef Q_2 //������ 2

#include "constants.h"		//������ ������������ ���� constants.h

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

#endif //������ 2



#ifdef Q_3 //������ 3

#include <iostream>

bool passOrFail()
{
	////��� �������:
	//static int count{ 0 };	//�������� ����������� ���������� count
	//if (count < 3)			//�������� count
	//{
	//	++count;			//�������������� count
	//	return true;		//������� ���������� true
	//}

	//return false;			//����� ������� ���������� 3 ����, ��� �������� ���������� false

	//������������ �������:
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

#endif //������ 3