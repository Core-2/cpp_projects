#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <sstream>

static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature(const std::string& name, char symbol, 
        int health = 4, int damage = 2, int gold = 0) :
            m_name{ name }, m_symbol{ symbol }, 
            m_health{ health }, m_damage{ damage },
            m_gold{ gold }
    {
    }

    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void addGold(int gold) { m_gold += gold; }
    void reduceHealth(int damage) { m_health -= damage; }
    bool isDead() const { return m_health <= 0; }
};

enum class PotionType
{
    health,
    strength,
    poison,
    max_types
};

enum class PotionSize
{
    small,
    medium,
    large,
    max_sizes
};

std::string getPotionTypeName(PotionType type)
{
    static constexpr std::array names
    {
        "Health",
        "Strength",
        "Poison"
    };

    return names.at(static_cast<std::size_t>(type));
}

std::string getPotionSizeName(PotionSize size)
{
    static constexpr std::array names
    {
        "Small",
        "Medium",
        "Large"
    };

    return names.at(static_cast<std::size_t>(size));
}

class Potion
{
private:
    PotionType m_type{};
    PotionSize m_size{};

    Potion(PotionType type, PotionSize size) :
        m_type{ type }, m_size{ size }
    {
    }

public:
    static Potion getRandomPotion()
    {
        static std::uniform_int_distribution types{ 0, static_cast<int>(PotionType::max_types) - 1 };
        static std::uniform_int_distribution sizes{ 0, static_cast<int>(PotionSize::max_sizes) - 1 };

        return Potion{ static_cast<PotionType>(types(mt)), static_cast<PotionSize>(sizes(mt)) };
    }

    PotionType getType() const { return m_type; }
    PotionSize getSize() const { return m_size; }

    std::string getName() const
    {
        std::stringstream result{};

        result << getPotionSizeName(m_size) << " potion of " << getPotionTypeName(m_type);

        return result.str();
    }
};

class Player : public Creature
{
private:
    int m_level{};

public:
    Player(const std::string& name, char symbol = '@', 
        int health = 10, int damage = 1, 
        int gold = 0, int level = 1) :
            Creature{ name, symbol, health, damage, gold }, 
            m_level{ level }
    {
    }

    void levelUp() 
    {
        ++m_level;
        ++m_damage;
    }

    void drinkPotion(const Potion& potion)
    {
        switch (potion.getType())
        {
        case PotionType::health:
            m_health += ((potion.getSize() == PotionSize::large) ? 5 : 2);
            break;

        case PotionType::strength:
            ++m_damage;
            break;

        case PotionType::poison:
            reduceHealth(1);
            break;

        case PotionType::max_types:
            break;
        }
    }
    
    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            {
                { "dragon", 'D', 20, 4, 100 },
                { "orc", 'o', 4, 2, 25 },
                { "slime", 's', 1, 1, 10 }
            }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type) : Creature{ getDefaultCreature(type) }
    {
    }

    static Monster getRandomMonster()
    {
        static std::uniform_int_distribution types{0, static_cast<int>(Type::max_types) - 1};

        return Monster{ static_cast<Type>(types(mt)) };
    }
};

void attackMonster(Player& player, Monster& monster)
{
    monster.reduceHealth(player.getDamage());
    std::cout << "You hit the " << monster.getName()
        << " for " << player.getDamage() << " damage.\n";

    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";

        player.addGold(monster.getGold());
        std::cout << "You found " << monster.getGold() << " gold.\n";
    }
}

void attackPlayer(const Monster& monster, Player& player)
{
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName()
        << " hit you for " << monster.getDamage() << " damage.\n";
}

void fightMonster(Player& player)
{
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a "
        << monster.getName() << " (" << monster.getSymbol() << ").\n";

    while (!player.isDead() && !monster.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char choice{};
        std::cin >> choice;

        if (choice == 'r' || choice == 'R')
        {
            static std::uniform_int_distribution runChance{ 0, 1 };
            if (runChance(mt))
            {
                std::cout << "You successfully fled.\n";
                return;
            }
            else
                std::cout << "You failed to flee.\n";
        }
        else if (choice == 'f' || choice == 'F')
        {
            attackMonster(player, monster);
            if (monster.isDead())
                return;
        }
        else
            continue;

        attackPlayer(monster, player);
    }
}

void findPotion(Player& player)
{
    if (player.isDead() || player.hasWon())
        return;

    static std::uniform_int_distribution findChance{ 1, 100 };
    if (findChance(mt) > 30)
        return;

    Potion potion{ Potion::getRandomPotion() };
    std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";

    while (true)
    {
        char choice{};
        std::cin >> choice;

        if (choice == 'n' || choice == 'N')
            return;
        else if (choice == 'y' || choice == 'Y')
        {
            player.drinkPotion(potion);
            std::cout << "You drank a " << potion.getName() << "!\n";
            return;
        }
        else
        {
            std::cout << "Wrong button! Try again! [y/n]: ";
        }
    }
}

int main()
{
    std::cout << "Enter your name: ";
    std::string playerName{};
    std::cin >> playerName;

    Player player{ playerName };

    std::cout << "Welcome, " << player.getName() << '\n';

    while (!player.isDead() && !player.hasWon())
    {
        fightMonster(player);
        findPotion(player);
    }

    if (player.hasWon())
    {
        std::cout << "Congratulations! You won!\n"
            << "You have " << player.getGold() << " gold. Good catch!\n";
    }
    else
    {
        std::cout << "You died at level " << player.getLevel()
            << " and with " << player.getGold() << " gold.\n"
            << "Too bad you can't take it with you!\n";
    }

    return 0;
}