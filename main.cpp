#include <algorithm>
#include <iostream>
#include <vector>

// Find, Modify, Filter

auto get_numbers()
{
        std::vector<int> nums {};
        std::cout << "Enter a list of numbers (0 to terminate): ";
        do {
                int num {};
                std::cin >> num;
                nums.push_back(num);
                if (num == 0) { break; }
        } while (true);

        return nums;
}

auto is_odd(int x) { return (x % 2 != 0); }

auto main() -> int
{
        auto nums = get_numbers();

        // find the first odd number
        // auto podd = std::find_if(nums.begin(), nums.end(), is_odd);
        // std::cout << *podd << '\n';

        // count_if -> count the no. of even numbers
}