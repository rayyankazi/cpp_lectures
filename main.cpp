#include <algorithm>
#include <iostream>

auto function_name(const int x) { return x * 2; }

struct Animal
{
        std::string name;

        Animal(std::string name) : name{name} {}

        auto say()
        {
                auto y = "foo";
                auto hello_greeting = [&, this]() {
                        std::cout << y << ' ';
                        std::cout << name << '\n';
                };

                hello_greeting();
        }
};

auto main() -> int
{
        auto y  = 45;
        auto y1 = 46;
        std::cout << "y before: " << y << '\n';
        std::cout << "y1 before: " << y1 << '\n';
        auto lambda_expression = [&](const int x) {
                y++;
                y1++;
                return x * 2;
        };        // non-capturing lambda expression

        lambda_expression(4);

        std::cout << "y after: " << y << '\n';
        std::cout << "y1 after: " << y1 << '\n';

        Animal cat("Cat");
        cat.say();
}