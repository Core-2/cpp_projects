#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int smaller{};                                  //smaller ��������� �����
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};                                   //larger ��������� �����
    std::cin >> larger;

    if (smaller > larger)
    {
        std::cout << "Swapping the values\n";
        int temp{ larger };                         //temp ��������� �����
        larger = smaller;
        smaller = temp;
    }                                               //temp ������������ �����

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}                                                   //larger � smaller ������������ �����