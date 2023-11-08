#include <array>
#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
    std::string m_name;
    std::string m_speak;

    // ћы делаем этот конструктор защищенным, потому что
    // не хотим, чтобы люди создавали объекты Animal напр€мую,
    // но мы по-прежнему хотим, чтобы производные классы могли
    // его использовать.
    Animal(std::string_view name, std::string_view speak)
        : m_name{ name }, m_speak{ speak }
    {
    }

    // ƒл€ предотвращени€ "нарезки" (будет рассмотрено позже)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name, "Meow"}
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name, "Woof"}
    {
    }

    std::string_view speak() const { return "Woof"; }
};

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // —оздаем массив указателей на животных и устанавливаем
    // эти указатели на наши объекты Cat и Dog
    const auto animals{ std::array<const Animal*, 6>({ &fred, &garbo, &misty,
                                                       &pooky, &truffle, &zeke }) };

    // ƒо C++ 20 с €вно указанным размером массива
    // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty,
    //                                             &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}