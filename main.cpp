#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
        // std::string fullname {};

        // std::cout << "Please enter your fullname (Firstname Lastname): ";
        // std::getline(std::cin, fullname);        // get name from user

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
        // std::string fullname_copy {};
        // fullname_copy += fullname;
        // std::cout << "fullname: " << fullname << '\n';
        // std::cout << "fullname_copy: " << fullname_copy << '\n';

        // Task 1: Copy the date from the user input into another variable.
        // Task 2: Copy the date from the user input into the end of another variable. (Hint: The destination must already contain a string).

        // Example - Count the vowels in a given string.
        // aeiou
        // The Quick Brown Fox Jumps Over the Lazy Dog

        std::string_view str {"The Quick Brown Fox Jumps Over the Lazy Dog"};
        // Method #1
        // int              num_vowels {0};
        // for (const auto c : str)
        // {
        //         const auto ch = std::tolower(c);
        //         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') { num_vowels += 1; }
        // }

        // Method #2
        // for (const auto v : "AaEeIiOoUu")
        // {
        //         // take vowel and find all occurences of it in str.
        //         int i = 0;
        //         while (true)
        //         {
        //                 i = str.find(v, i);
        //                 if (i != std::string_view::npos)
        //                 {
        //                         num_vowels += 1;
        //                         i += 1;
        //                 }
        //                 else { break; }
        //         }
        // }

        // Method #3
        // std::string_view vowels {"AaEeIiOoUu"};
        // for (int i = 0;;)
        // {
        //         i = str.find_first_of(vowels, i);
        //         if (i != std::string_view::npos)
        //         {
        //                 num_vowels += 1;
        //                 i += 1;
        //         }
        //         else { break; }
        // }
        // std::cout << num_vowels << '\n';

        // Method #4
        // const auto       num_vowels = std::count_if(str.begin(), str.end(), [](const auto c) {
        //         const auto ch = std::tolower(c);
        //         return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        // });
        // std::cout << num_vowels << '\n';

        // Task: Count all consonants in string_view. (Hint: Consonants are the alphabet that's not a vowel. See `find_first_not_of`)

        // TODO(CA): Count everything that's not a vowel using find. Find the substrings and length of substring - vowels.
        // int              num_consonents {0};
        // for (const auto v : "AaEeIiOoUu")
        // {
        //         // take vowel and find all occurences of it in str.
        //         int i = 0;
        //         while (true)
        //         {
        //                 i = str.find(v, i);
        //                 if (i != std::string_view::npos)
        //                 {
        //                         num_vowels += 1;
        //                         i += 1;
        //                 }
        //                 else { break; }
        //         }
        // }

        // Checks if the given character is a consonant.
        constexpr auto   is_consonant = [](const auto c) {
                if (!std::isalpha(c)) { return false; }

                const auto lch = std::tolower(c);
                return !(lch == 'a' || lch == 'e' || lch == 'i' || lch == 'o' || lch == 'u');
        };

        const auto num_consonents = std::count_if(str.begin(), str.end(), is_consonant);
        std::cout << num_consonents << '\n';
}