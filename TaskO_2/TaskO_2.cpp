#include <bitset>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
    ////Вопрос 2
    //bool leftbit{ bits.test(3) };
    //bits <<= 1;
    //if (leftbit)
    //    bits.set(0);

    //return bits;

    //Вопрос 3
    std::bitset<4> mask1{ 0b1000 };
    std::bitset<4> mask2{ 0b0001 };
    std::bitset<4> check{bits & mask1};
    bits <<= 1;
    if (check == mask1)
        bits |= mask2;

    return bits;
}

int main()
{
    std::bitset<4> bits1{ 0b0001 };
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{ 0b1001 };
    std::cout << rotl(bits2) << '\n';

    return 0;
}