#include "constants.h"
#include <iostream>

//������� ��������� ������ ����� �� ������������:
double getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;
    return height;
}

//������� �������� ������ ���� ����� "seconds" ������
double calculateHeight(double height, int seconds)
{
    return height - (constants::g * seconds * seconds / 2.0);
}

//������� ������ ���������� �� ����� �������:
void writeAnswer(double height, int seconds)
{
    if (height > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

//�������, ������������ calculateHeight() � writeAnswer():
void calculateAndPrintHeight(double height, int seconds)
{
    double ballHeight{ calculateHeight(height, seconds) };
    writeAnswer(ballHeight, seconds);
}

int main()
{
    double height{ getHeight() };

    calculateAndPrintHeight(height, 1);
    calculateAndPrintHeight(height, 2);
    calculateAndPrintHeight(height, 3);
    calculateAndPrintHeight(height, 4);
    calculateAndPrintHeight(height, 5);

    return 0;
}