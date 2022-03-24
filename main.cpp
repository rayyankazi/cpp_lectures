#include <algorithm>
#include <iostream>
#include <vector>

enum class ShoeBrands
{
        Nike,
        Adidas,
        Clarks,
};

struct DatabaseItem
{
        ShoeBrands brand;
        float      cost;
};

auto operator==(DatabaseItem& lhs, DatabaseItem& rhs) -> bool { return lhs.brand == rhs.brand; }

auto main() -> int
{
        DatabaseItem x1 {ShoeBrands::Adidas, 45.F};
        DatabaseItem x2 {ShoeBrands::Nike, 70.F};
        const auto   is_same = x1 == x2;
        std::cout << is_same << '\n';

        /*
        std::vector<DatabaseItem> database {};

        std::cin >> brand_input;

        std::vector<int> numbers {};
        while (true)
        {
                int number {};
                std::cin >> number;
                numbers.push_back(number);
                if (number == 0) { break; }
        }

        const auto n = std::count_if(numbers.begin(), numbers.end(), [](int x) { return (x % 2 != 0); });
        std::cout << "Number of odd numbers: " << n << '\n';
        */
}