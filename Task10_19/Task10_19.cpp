#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view names[]{"Alex", "Betty", "Caroline", 
                             "Dave", "Emily", "Fred", 
                             "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string enteredName{};
    std::cin >> enteredName;

    bool isNameFound{ false };
    for (const auto name : names)
    {
        if (name == enteredName)
        {
            isNameFound = true;
            break;
        }
    }

    if (isNameFound)
        std::cout << enteredName << " was found.\n";
    else
        std::cout << enteredName << " was not found.\n";
    return 0;
}