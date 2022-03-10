#include <algorithm>          // std::remove
#include <cctype>             // std::isspace
#include <iostream>           // std::cin
#include <string>             // std::string
#include <string_view>        // std::string_view

int main()
{
        // Copy, Substring, Find, Join
        std::string name {};
        std::cout << "Enter your full name (Firstname Lastname): ";
        std::getline(std::cin, name);

        // We're assuming that we're using the UK naming convention. Firstname Lastname
        std::string firstname {};
        std::string lastname {};

        // "Amine Mihoubi"
        // Task: Check if the input string contains no space characters in the front.

        constexpr auto is_space = [](const char c) { return c == ' '; };
        const auto  sp = std::find_if_not(name.begin(), name.end(), is_space);
        if (sp != name.end())
        {
                std::cout << sp[0] << '\n';

                const auto beg       = name.find(*sp);
                // print the first and lastnames as Firstname.Lastname
                const auto space_pos = name.find(' ', beg);
                std::cout << space_pos - beg << '\n';
                firstname = name.substr(beg, space_pos - beg);        // get the first part of the string until ' '
                lastname  = name.substr(space_pos + 1);               // get the rest of the string

                // put the first and lastnames together joined by a '.'
                std::string fullname {firstname};
                (fullname += '.') += lastname;
                std::cout << fullname << '\n';
        }

        // lstrip or trim or remove the leading space character
        // while (true)
        // {
        //         if (name[0] != ' ') { break; }

        //         // find the location of the first space character starting from the beginning to the end of name
        //         const auto space_pos = std::find(name.begin(), name.end(), ' ');
        //         // remove the space character at this location
        //         const auto c         = name.erase(space_pos);
        //         if (c[0] != ' ') { break; }
        // }
        // std::cout << name << '\n';

        // // print the first and lastnames as Firstname.Lastname
        // const auto space_pos = name.find(' ');
        // firstname            = name.substr(0, space_pos);         // get the first part of the string until ' '
        // lastname             = name.substr(space_pos + 1);        // get the rest of the string

        // // put the first and lastnames together joined by a '.'
        // std::string fullname {firstname};
        // (fullname += '.') += lastname;
        // std::cout << fullname << '\n';
}