#include <iostream>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) 
{
    int size{ static_cast<int>(snail_map[0].size()) };
    
    std::vector<int> result{};
    if (size == 0)
        return result;

    if (size == 1)
    {
        result.push_back(snail_map[0][0]);
        return result;
    }
    int row{ 0 };
    int column{ 0 };
    int start{ 0 };

    while (start != size)
    {
        while (column < size)
            result.push_back(snail_map[row][column++]);

        --column;
        ++row;
        while (row < size)
            result.push_back(snail_map[row++][column]);

        --row;
        --column;
        while (column >= start)
            result.push_back(snail_map[row][column--]);

        ++column;
        --row;
        while (row > start)
            result.push_back(snail_map[row--][column]);

        ++start;
        --size;
        if (size - start == 1)
        {
            result.push_back(snail_map[start][start]);
            return result;
        }
            
        row = column = start;
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> snail_map{ {} };
    std::vector<int> result{snail(snail_map)};

    for (const auto element : result)
    {
        std::cout << element << ' ';
    }

    return 0;
}