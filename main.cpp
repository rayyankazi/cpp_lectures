#include <cmath>
#include <iostream>
#include <vector>

constexpr auto MAX_OPERATIONS = 6;

/*
    Add, Sub, Mul, Div
    New Operations: Power and Remainder
*/

auto           add(float x, float y) { return x + y; }
auto           sub(float x, float y) { return x - y; }
auto           mul(float x, float y) { return x * y; }
auto           div(float x, float y) { return x / y; }

using BinaryOp = float (*)(float, float);

auto main() -> int
{
        std::vector<BinaryOp> ops {add, sub, mul, div};

        std::cout << "Calc v0.1" << '\n';
        do {
                std::cout << "Enter 0 to exit." << '\n';
                std::cout << "Select operation (1: Add, 2: Sub, 3: Mul, 4: Div), (5-6) Slot Available for `Pow` and `Rem`: ";

                int uop {};
                std::cin >> uop;
                if (uop < 1 || uop > 4)
                {
                        if (uop == 0) { break; }

                        if (uop > 4 && uop < MAX_OPERATIONS)
                        {
                                // user probably wants to add new functions
                                if (ops.size() < (MAX_OPERATIONS + 1))
                                {
                                        std::cout << "(p)Pow, (r)Rem: ";
                                        char selection {};
                                        std::cin >> selection;
                                        if (selection == 'p') { ops.push_back(std::pow); }
                                        else if (selection == 'r') { ops.push_back(std::fmod); }
                                }
                        }
                        else
                        {
                                std::cout << "Invalid operation selected. Please try again!";
                                continue;
                        }
                }

                const auto op = ops[uop - 1];

                float      x {}, y {};
                std::cout << "Enter two numbers (a b): ";
                std::cin >> x;
                std::cin >> y;

                const auto res = op(x, y);
                std::cout << "Result: " << res << '\n';
        } while (true);
}