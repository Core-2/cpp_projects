#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>

// array - ��� ������ ��� ������.
// target - ��� ��������, ������� �� �������� ����������, ���� ��� ��� ���.
// min - ��� ������ ������ ������� �������, � ������� �� ����.
// max - ��� ������ ������� ������� �������, � ������� �� ����.
// binarySearch() ������ ���������� ������ �������� ��������, ���� target ������, ����� -1

namespace iteration
{
    int binarySearch(const int* array, int target, int min, int max)
    {
        assert(array);

        while (min <= max)
        {
            int middleElement{ std::midpoint(min, max) };

            if (array[middleElement] == target)
                return middleElement;
            else if (array[middleElement] < target)
                min = middleElement + 1;
            else
                max = middleElement - 1;
        }

        return -1;
    }
}

inline namespace recursion
{
    int binarySearch(const int* array, int target, int min, int max)
    {
        assert(array);

        if (min > max)
            return -1;

        int middleElement{ std::midpoint(min, max) };

        if (array[middleElement] == target)
            return middleElement;
        else if (array[middleElement] < target)
            min = middleElement + 1;
        else
            max = middleElement - 1;

        return binarySearch(array, target, min, max);
    }
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // �� ���������� �������������� ����� ��������, ����� �������,
    // ���� �� ��� ��������� ����������
    constexpr int numTestValues{ 9 };
    // ��� �������� ��������
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // � ��� ��������� ���������� ��� ������� ��������
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // ���������� ��� �������� ��������
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // �������, ���� �� ���� �������� �������� � �������
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // ���� ��������� ������������� ����������, ����� �������!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // ����� ���� ������� binarySearch() �� ��������
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}