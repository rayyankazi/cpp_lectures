#include <algorithm>
#include <iostream>
#include <vector>

auto main() -> int
{
        std::vector<int> nums {};

        std::cout << "Enter numbers (0 to terminate): ";
        do {
                int num {};
                std::cin >> num;
                nums.push_back(num);
                if (num == 0) { break; }
        } while (true);

        // find the first odd number and delete it
        int unum {8};
        std::cin >> unum;

        nums.erase(std::find_if(nums.begin(), nums.end(), [&](const auto& n) { return n == unum; }));
        // print items in nums
        std::for_each(nums.begin(), nums.end(), [](const auto& n) { std::cout << n << '\n'; });
}