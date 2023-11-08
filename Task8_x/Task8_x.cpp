#define Q_2			//������ 2
//#define Q_5A		//������ 5a
//#define Q_5B		//������ 5b
//#define Q_5C		//������ 5c


#ifdef Q_2 //������ 2

#include <iostream>

namespace Constants
{
    inline constexpr double pi{ 3.14159 };
}

using radians_t = double;
using degrees_t = double;

radians_t convertToRadians(degrees_t degrees)
{
    return degrees * Constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    degrees_t degrees{};
    std::cin >> degrees;

    radians_t radians{ convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}

#endif //������ 2



#ifdef Q_5A //������ 5a

#include <iostream>

// �������� ����� ���� ������ ������� add
template <typename T>
T add(T x, T y)
{
	return x + y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	return 0;
}

#endif //������ 5a



#ifdef Q_5B //������ 5b

#include <iostream>

// �������� ����� ���� ������ ������� mult
template <typename T>
T mult(T x, int y)
{
	return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}

#endif //������ 5b



#ifdef Q_5C //������ 5c

#include <iostream>

// �������� ����� ���� ������ ������� sub
template <typename T, typename U>
auto sub(T x, U y)
{
	return x - y;
}

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}

#endif //������ 5c