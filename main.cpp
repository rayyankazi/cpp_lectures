#include <algorithm>
#include <iostream>
#include <string>

int main()
{
        std::string fullname {};

        std::cout << "Please enter your fullname (Firstname Lastname): ";
        std::getline(std::cin, fullname);        // get name from user

        // Copy #1
        // std::string fullname_copy {};
        // fullname_copy = fullname;

        // Copy #2
        // std::string fullname_copy {fullname};

        // Copy #3
        // std::string fullname_copy(fullname.size(), '\0');
        // fullname.copy(fullname_copy.data(), fullname_copy.size());

        // Copy #4
        // std::string fullname_copy(fullname.size(), '\0');
        // std::copy(fullname.begin(), fullname.end(), fullname_copy.begin());
        // std::cout << "fullname: " << fullname << '\n';
        // std::cout << "fullname_copy: " << fullname_copy << '\n';

        // Copy #5
        std::string fullname_copy {};
        fullname_copy += fullname;
        std::cout << "fullname: " << fullname << '\n';
        std::cout << "fullname_copy: " << fullname_copy << '\n';

        // Task 1: Copy the date from the user input into another variable.
        // Task 2: Copy the date from the user input into the end of another variable. (Hint: The destination must already contain a string).

        // Example - Count the vowels in a given string.
        
}