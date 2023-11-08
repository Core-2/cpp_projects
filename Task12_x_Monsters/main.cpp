#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <string_view>

class Monster           // Вопрос 3b
{
public:
    enum class Type  // Вопрос 3c
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,

        max_monster_types
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

public:
    Monster()
    {

    }
    Monster(Type type, const std::string& name, 
            const std::string& roar, int hitPoints)
        : m_type{ type }, m_name{ name }, 
          m_roar{ roar }, m_hitPoints{ hitPoints }
    {
        // Вопрос 3d
    }

    // Вопрос 3e
    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case Monster::Type::dragon:     return "dragon";
        case Monster::Type::goblin:     return "goblin";
        case Monster::Type::ogre:       return "ogre";
        case Monster::Type::orc:        return "orc";
        case Monster::Type::skeleton:   return "skeleton";
        case Monster::Type::troll:      return "troll";
        case Monster::Type::vampire:    return "vampire";
        case Monster::Type::zombie:     return "zombie";
        default:                        return "UNKNOWN";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString()
                  << " has " << m_hitPoints << " hit points and says " 
                  << m_roar << '\n';
    }
};

class MonsterGenerator  // Вопрос 3f
{
private:
    static std::mt19937 s_mt;

public:
    static Monster generateMonster()
    {
        static constexpr std::array s_names
        {
            "Joe", "Billy", "Tobias",
            "Frank", "Lenny", "Sammy"
        };
        static constexpr std::array s_roars
        {
            "*whine*", "*hum*", "*scream*",
            "*burp*", "*roar*", "*squeal*"
        };

        static std::uniform_int_distribution randomType{ 0, static_cast<int>(Monster::Type::max_monster_types) - 1 };
        static std::uniform_int_distribution randomHP{ 1, 100 };
        static std::uniform_int_distribution randomName{ 1, static_cast<int>(s_names.size()) - 1 };
        static std::uniform_int_distribution randomRoar{ 1, static_cast<int>(s_roars.size()) - 1 };

        return Monster(
            static_cast<Monster::Type>(randomType(s_mt)), 
            s_names[randomName(s_mt) - 1],
            s_roars[randomRoar(s_mt) - 1],
            randomHP(s_mt));
    }
};

std::mt19937 MonsterGenerator::s_mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

int main()
{
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();

    m = MonsterGenerator::generateMonster();
    m.print();

    return 0;
}