#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm> // std::count_if

constexpr auto MAX_WORD_LEN = 32;

auto           copy_word(const std::string& src, const int i, std::array<char, MAX_WORD_LEN>& dst, const char delim = ' ') -> int
{
        dst.fill('\0');

        // copy into word from input till whitespace character is found
        int n = 0;
        for (auto k = 0, j = i; j < src.size() && k < dst.size(); k += 1, j += 1)
        {
                const auto ch = src[j];
                if (ch == delim) { break; }
                dst[k] = src[j];
                n += 1;        // increment the no. of characters copied
        }

        return n;
}

auto main() -> int
{
        // Input: The quick brown fox jumps over the lazy dog
        //         3   5      5    3   5    4     3    4  3
        std::array<char, MAX_WORD_LEN> word {};

        std::cout << "Enter a few words: ";
        std::string input {};
        std::getline(std::cin, input);

        std::cout << "Input: " << input << '\n';
        std::cout << input.size() << '\n';

        // Use a loop to extract and count the number of characters in each word in the sentence.
        int i = 0;
        do {
                // copy into word from input till whitespace character is found
                const auto n = copy_word(input, i, word, ' ');
                i += (n + 1);        // move the cursor by n steps

                // count number of valid characters in word
                std::cout << "[" << word.data() << "] - " << n << '\n';
        } while (i < input.size());
}