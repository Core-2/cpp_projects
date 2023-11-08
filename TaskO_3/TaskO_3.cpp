#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    constexpr std::uint_fast8_t option_viewed{ 0x01 };
    constexpr std::uint_fast8_t option_edited{ 0x02 };
    constexpr std::uint_fast8_t option_favorited{ 0x04 };
    constexpr std::uint_fast8_t option_shared{ 0x08 };
    constexpr std::uint_fast8_t option_deleted{ 0x10 };

    std::uint_fast8_t myArticleFlags{ option_favorited };

    //a) Напишите строку кода, чтобы сделать статью просматриваемой 
    // (включить флаг option_viewed).

    myArticleFlags |= option_viewed;

    //b) Напишите строку кода, чтобы проверить, была ли удалена 
    // статья (флаг option_deleted).

    //if (myArticleFlags & option_deleted)

    //c) Напишите строку кода, чтобы сбросить у статьи статус 
    // избранная (сбросить флаг option_favorited).

    myArticleFlags &= ~option_favorited;

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}