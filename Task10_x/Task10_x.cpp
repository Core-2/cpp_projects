#define Q_6

#ifdef Q_1 // Вопрос 1

#include <iostream>
#include <array>
#include <numeric>


enum ItemTypes
{
    item_health_potion,
    item_torch,
    item_arrow,
    max_items
};

using inventory_type = std::array<int, ItemTypes::max_items>;   // Создание псевдонима типа

int countTotalItems(inventory_type arrItems)
{
    return std::reduce(arrItems.begin(), arrItems.end());
}

int main()
{
    std::array playerItems{2, 5, 10};

    std::cout << "Player has " << countTotalItems(playerItems) << " items in total.\n";
    std::cout << "Player has " << playerItems[ItemTypes::item_torch] << " torches.\n";
    return 0;
}

#endif // Вопрос 1



#ifdef Q_2 // Вопрос 2

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>

// Структура Student, содержащая имя студента и его оценку (по шкале от 0 до 100)
struct Student
{
    std::string name{};
    int score{};
};

// Функция получения от пользователя количества студентов,
// которое он хочет ввести
int getStudentsQuantity()
{
    std::cout << "How many students do you want to enter? ";
    int value{};
    std::cin >> value;
    return value;
}

// Функция получения от пользователя пары имени и оценки
// каждого студента и сохранения этих данных в vector
void getStudentsInfo(std::vector<Student>& students)
{
    for (int i{1}; auto& student : students)
    {
        std::cout << "Enter student name #" << i << ": ";
        std::cin >> student.name;

        std::cout << "Enter student score #" << i << ": ";
        std::cin >> student.score;

        ++i;
    }
}

// Функция сортировки вектора по оценкам студентов
bool compareStudents(const Student& a, const Student& b)
{
    return (a.score > b.score);
}

// Функция вывода данных из вектора в отсортированном порядке
void printSortedInfo(std::vector<Student>& students)
{
    std::sort(students.begin(), students.end(), compareStudents);

    std::cout << '\n';
    for (auto& student : students)
        std::cout << student.name << " got a grade of " << student.score << '\n';
}

int main()
{
    int studentsQuantity{ getStudentsQuantity() };      // Запрашиваем у пользователя кол-во студентов

    std::vector<Student> students(studentsQuantity);    // Создаем вектор students с размером, указанным ранее

    getStudentsInfo(students);                          // Запрашиваем у пользователя пары имен и оценок студентов

    printSortedInfo(students);                          // Выводим отсортированные данные в консоль

    return 0;
}

#endif // Вопрос 2



#ifdef Q_3 // Вопрос 3

#include <iostream>

void swap(int& a, int& b)
{
    int temp{ a };
    a = b;
    b = temp;
}

int main()
{
    int x{ 5 };
    int y{ 2 };
    std::cout << "x = " << x << "\ny = " << y << '\n';

    swap(x, y);

    std::cout << "\nSwap!\n\n";
    std::cout << "x = " << x << "\ny = " << y << '\n';
    return 0;
}

#endif // Вопрос 3

#ifdef Q_4 // Вопрос 4

#include <iostream>

void printCStyleString(const char* str)
{
    while (*str != '\0')
    {
        std::cout << *str;
        ++str;
    }
}

int main()
{
    printCStyleString("Hello, world!");
    return 0;
}

#endif // Вопрос 4



#ifdef Q_6 // Вопрос 6

#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>

enum class CardRank
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,

    max_ranks
};

enum class CardSuit
{
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

enum class BlackjackResult
{
    player_win,
    dealer_win,
    tie
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

struct Player
{
    int score{};
    int acesCount{};
};

void printCard(const Card& card)
{
    switch (card.rank)
    {
    case CardRank::Two:
        std::cout << 2;
        break;
    case CardRank::Three:
        std::cout << 3;
        break;
    case CardRank::Four:
        std::cout << 4;
        break;
    case CardRank::Five:
        std::cout << 5;
        break;
    case CardRank::Six:
        std::cout << 6;
        break;
    case CardRank::Seven:
        std::cout << 7;
        break;
    case CardRank::Eight:
        std::cout << 8;
        break;
    case CardRank::Nine:
        std::cout << 9;
        break;
    case CardRank::Ten:
        std::cout << "T";
        break;
    case CardRank::Jack:
        std::cout << "J";
        break;
    case CardRank::Queen:
        std::cout << "Q";
        break;
    case CardRank::King:
        std::cout << "K";
        break;
    case CardRank::Ace:
        std::cout << "A";
        break;
    default:
        std::cout << "?";
        break;
    }

    switch (card.suit)
    {
    case CardSuit::clubs:
        std::cout << "C";
        break;
    case CardSuit::diamonds:
        std::cout << "D";
        break;
    case CardSuit::hearts:
        std::cout << "H";
        break;
    case CardSuit::spades:
        std::cout << "S";
        break;
    default:
        std::cout << "?";
        break;
    }
}

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

constexpr int maxScore{ 21 };
constexpr int minDealerScore{ 17 };
constexpr int aceScore{ 11 };

deck_type createDeck()
{
    deck_type deck{};
    index_type index{ 0 };

    int maxSuits{ static_cast<int>(CardSuit::max_suits) };
    int maxRanks{ static_cast<int>(CardRank::max_ranks) };

    for (int suit{ 0 }; suit < maxSuits; ++suit)
    {
        for (int rank{ 0 }; rank < maxRanks; ++rank)
        {
            deck[index].rank = (static_cast<CardRank>(rank));
            deck[index].suit = (static_cast<CardSuit>(suit));
            ++index;
        }
    }

    return deck;
}

void printDeck(const deck_type& deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

void shuffleDeck(deck_type& deck)
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
    if (card.rank < CardRank::Ten)
        return (static_cast<int>(card.rank) + 2);
    else if (card.rank >= CardRank::Ten && card.rank < CardRank::Ace)
        return 10;
    else if (card.rank == CardRank::Ace)
        return 11;
    else
        return -1;
}

void takeCard(Player& player, const Card& card)
{
    int cardValue{ getCardValue(card) };

    if (cardValue == aceScore)
    {
        std::cout << "Ace is taken!\n";
        ++player.acesCount;
    }

    player.score += cardValue;

    if (player.score > maxScore)
    {
        if (player.acesCount > 0)
        {
            --player.acesCount;
            player.score -= aceScore;
            ++player.score;
            std::cout << "Ace reduced from 11 to 1!\n";
        }
    }
}

bool isPlayerHit()
{
    while (true)
    {
        std::cout << "Enter \"h\", if you want to hit, otherwise, enter \"s\": ";
        char choice{};
        std::cin >> choice;

        if (std::cin.fail())
            std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

bool playerTurn(const deck_type& deck, index_type& cardCount, Player& player)
{
    while (true)
    {
        if (player.score > maxScore)
        {
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (isPlayerHit())
            {
                takeCard(player, deck[cardCount]);
                int cardValue{ getCardValue(deck[cardCount++]) };
                std::cout << "You take a card with value: " << cardValue << '\n';
                std::cout << "Your score is " << player.score << '\n';
            }
            else
            {
                return false;
            }
        }
    }
}

bool dealerTurn(const deck_type& deck, index_type& cardCount, Player& dealer)
{
    while (dealer.score < minDealerScore)
    {
        takeCard(dealer, deck[cardCount]);
        int cardValue{ getCardValue(deck[cardCount++]) };
        std::cout << "Dealer takes a card with value: " << cardValue << '\n';
        std::cout << "Dealer's score is " << dealer.score << '\n';
    }

    if (dealer.score > maxScore)
    {
        std::cout << "Dealer busted!\n";
        return true;
    }

    return false;
}

BlackjackResult playBlackjack(const deck_type& deck)
{
    index_type cardCount{ 0 };
    Player dealer{ 0, 0 };
    takeCard(dealer, deck[cardCount++]);
    std::cout << "Dealer's score is " << dealer.score << '\n';

    Player player{ 0, 0 };
    takeCard(player, deck[cardCount++]);
    takeCard(player, deck[cardCount++]);
    std::cout << "Your score is " << player.score << '\n';

    if (playerTurn(deck, cardCount, player))
    {
        return BlackjackResult::dealer_win;
    }

    if (dealerTurn(deck, cardCount, dealer))
    {
        return BlackjackResult::player_win;
    }

    if (player.score > dealer.score)
        return BlackjackResult::player_win;
    else if (player.score < dealer.score)
        return BlackjackResult::dealer_win;
    else
        return BlackjackResult::tie;
}

int main()
{
    deck_type deck{ createDeck() };

    std::cout << "Welcome to Blackjack!\n";

    char exitBtn{};
    do
    {
        shuffleDeck(deck);

        BlackjackResult gameResult{ playBlackjack(deck) };
        switch (gameResult)
        {
        case BlackjackResult::dealer_win:
            std::cout << "You lose!\n";
            break;
        case BlackjackResult::player_win:
            std::cout << "You won!\n";
            break;
        case BlackjackResult::tie:
            std::cout << "There is a tie!\n";
        }

        std::cout << "\nPress any key to continue, or \"e\", if you want to exit: ";
        std::cin >> exitBtn;

        if (std::cin.fail())
            std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (exitBtn != 'e');

    return 0;
}

#endif // Вопрос 6

