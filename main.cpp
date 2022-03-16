#include <algorithm>        // std::accumulate, std::reduce
#include <array>            // std::array
#include <iostream>         // std::cout, std::cin, std::scanf
#include <iterator>         // std::istream_iterator
#include <sstream>
#include <string>         // std::string
#include <utility>        // std::pair

constexpr auto NUM_FUNCTIONS = 7;

auto           ask_user_continue() -> bool
{
        std::cout << "Would you like to continue (y/n): ";
        char opt {};
        std::cin >> opt;
        return opt != 'n';
}

auto ask_user_arithemtic() -> int
{
        std::cout << "Press 'a' for addition." << '\n';
        std::cout << "Press 's' for subtraction." << '\n';
        std::cout << "Press 'm' for multiplication." << '\n';
        std::cout << "Press 'd' for division." << '\n';
        std::cout << "Press 'r' for remainder." << '\n';
        std::cout << "Press 'p' for power." << '\n';

        char opt {};
        std::cin >> opt;
        switch (opt)
        {
                case 'a': return 1;
                case 's': return 2;
                case 'm': return 3;
                case 'd': return 4;
                case 'r': return 5;
                case 'p': return 6;
                default: return 0;
        }
}

auto ask_user_numbers() -> std::pair<float, float>
{
        std::cout << "Enter two numbers (x y): ";
        float x {}, y {};
        std::scanf("%f %f", &x, &y);
        return std::make_pair(x, y);
}

// Task 1 -> Implement the power and remainder operations.
// Task 2 -> Declare the `res` variable.
// Task 3 -> Create an array containing functions that perform arithmetic. (Hint: See example)

// Keyword: Function Signature -> ReturnType (Parameters...)
using BinaryFn = float (*)(float, float);

constexpr auto                                nop(float x, float y) -> float { return 0; }

constexpr auto                                add(float x, float y) -> float { return x + y; }

constexpr std::array<BinaryFn, NUM_FUNCTIONS> FN {nullptr, add};

auto                                          main() -> int
{
        /*
        std::cout << "Calculator v0.3" << '\n';

        char opt {};
        do {
                const auto op     = ask_user_arithemtic();
                const auto [a, b] = ask_user_numbers();
                if (op < 1 || op > 6)
                {
                        std::cout << "Unknown operation selected. Please select again." << '\n';
                        continue;
                }
                const auto fn = FN[op];
                std::cout << "Result: " << fn(a, b) << '\n';
                if (!ask_user_continue()) { break; }
        } while (true);
        */

        // Example: User gives a list of numbers to compute the sum of.
        std::cout << "Enter a list of numbers separated by a space (0 to terminate): ";
        std::vector<float> nums {};
        float              num {};
        do {
                std::cin >> num;
                if (num == 0) { break; }
                nums.push_back(num);
        } while (true);

        // std::istream_iterator to process directly from std::cin
        // Pointers (*), References (&), nullptr, Lambda Expressions
        // Structs
        float sum {};
        std::for_each(nums.begin(), nums.end(), [&](float x) { sum += x; });
        std::cout << sum << '\n';
}