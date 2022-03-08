#include <cstdio>
#include <iostream>           // std::cin
#include <string>             // std::string
#include <string_view>        // std::string_view

int main()
{
        // std::string name {};
        // std::cout << "Please enter your name: ";
        // // std::cin >> name;
        // std::getline(std::cin, name);
        // std::cout << name << '\n';

        // Task: Ask the user to enter a date in DD.MM.YYYY and display it.
        // std::cin and std::cout and std::string
        // std::string date {};
        // std::cout << "Please enter a date (DD.MM.YYYY): ";
        // std::cin >> date;
        // // std::getline(std::cin, date);
        // std::cout << date << '\n';

        // TYPE NAME VALUE
        std::string      name {};        //  allocates space to store characters
        std::string_view msg {"Please enter a name: "};
        // std::string_view name {};        // it's like VR goggles -> doesn't allocate space for characters
        // std::getline(std::cin, name);

        std::cout << msg;

        auto ch {'\0'};
        // Processes one line of input character by character until '\n' is found.
        // This loop will display the '\n' character as well.
        do {
                std::cin.get(ch);
                // std::scanf(" %c", &ch);

                switch (ch)
                {
                        case 'a': ch = '4'; break;
                        case 'e': ch = '3'; break;
                        case 'i': ch = '1'; break;
                        case 'o': ch = '0'; break;
                        case 'u': ch = '_'; break;
                        default: break;
                }
                std::cout << ch;
        } while (ch != '\n');

        // std::getline(std::cin, name);

        // for (auto c : name) { std::cout << c << '.'; }
        // std::cout << '\n';

        // Task: Replace the '.' with a '-'
        // Task: Check if the character in the name is a vowel. Then we print a number in its place.
        // a - 4, e - 3, i - 1, o - 0, u - _
        // For example: Joe Rogan -> J03 R0g4n

        // Copy, Substring, Find, Join
}