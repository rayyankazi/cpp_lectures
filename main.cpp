#include <iostream>
#include <string>
#include <vector>

auto say_hello() -> void { std::cout << "Hello World" << '\n'; }

auto get_name() -> std::string
{
        std::string name {};
        std::cout << "Enter your full name: ";
        std::getline(std::cin, name);
        return name;
}

auto get_two_ints(int& x, int& y)
{
        std::cout << "Enter two integers: ";
        std::cin >> x;
        std::cin >> y;
}
auto compute_addition(int x, int y) -> int { return x + y; }
auto compute_subtraction(int x, int y) -> int { return x - y; }
// Multiplication, Division, Power, and Remainder

using BinaryFn = int (*)(int, int);

auto main() -> int
{
        int x {}, y {};
        get_two_ints(x, y);

        std::vector<BinaryFn> functions {};
        functions.push_back(compute_subtraction);
        functions.push_back(compute_addition);

        int op {};
        std::cout << "Select Operation (1: add, 2: sub): ";
        std::cin >> op;
        if (op == 1)
        {
                const auto operation = functions[0];
                const auto res = operation(x, y);
                std::cout << res << '\n';
        }
}