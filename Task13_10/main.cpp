#include <cassert>
#include <iostream>
#include <string>

class Mystring
{
private:
    std::string m_str{};

public:
    Mystring(const std::string& str = {})
        : m_str{ str }
    {
    }

    std::string operator()(int start, int size)
    {
        assert(start >= 0);
        assert(start + size <= static_cast<int>(m_str.length())
            && "Mystring::operator(int, int): Substring is out of range");
        std::string result{};

        for (int i{ 0 }; i < size; ++i)
            result += m_str[static_cast<std::string::size_type>(start + i)];

        return result;
    }
};

int main()
{
    Mystring string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // начинаем с индекса 7 и возвращаем 5 символов

    return 0;
}