#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// The Sky is blue -> [The, Sky, is, blue]
// TheSkyBlue

using Words = std::vector<std::string>;

auto extract_words(Words& words, std::string text, std::string_view separators)
{
        auto   start = text.find_first_not_of(separators);
        size_t end {};

        while (start != std::string::npos)
        {
                end = text.find_first_of(separators, start + 1);
                if (end == std::string_view::npos) { end = text.length(); }
                std::string s {text.substr(start, end - start)};
                words.push_back(s);
                start = text.find_first_not_of(separators, end + 1);
        }
}

auto main() -> int
{
        std::cout << "Enter some text: ";
        std::string input {};
        std::getline(std::cin, input);
        Words words {};
        extract_words(words, input, " \t");

        std::for_each(words.begin(), words.end(), [](auto& w) { std::cout << w << '\n'; });
}
