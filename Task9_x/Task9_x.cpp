#include <iostream>
#include <string>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster
{
    MonsterType type{};
    std::string name{};
    int health{};
};

std::string getMonsterType(Monster monster)
{
    switch (monster.type)
    {
    case MonsterType::ogre:
        return "Ogre";
    case MonsterType::dragon:
        return "Dragon";
    case MonsterType::orc:
        return "Orc";
    case MonsterType::giant_spider:
        return "Giant spider";
    case MonsterType::slime:
        return "Slime";
    default:
        return "Error in getting MonsterType!";
    }
}

void printMonster(Monster monster)
{
    std::cout << "This " << getMonsterType(monster) << " is named " << monster.name;
    std::cout << " and has " << monster.health << " health.\n";

}

int main()
{
    Monster ogreTorg{ MonsterType::ogre, "Torg", 145 };
    Monster slimeBlurp{ MonsterType::slime, "Blurp", 23 };

    printMonster(ogreTorg);
    printMonster(slimeBlurp);
    return 0;
}