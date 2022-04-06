#include <initializer_list>
#include <iostream>
#include <vector>

template<typename T>
class Array
{
        std::vector<T> data;
        int            nr, nc;

      public:
        Array(int nr, int nc) : data(nr * nc), nr {nr}, nc {nc} {}
        Array(std::initializer_list<T> val) : data {val}, nr {1}, nc {static_cast<int>(val.size())} {}

        auto put(int i, int j, T v) { data[i * nc + j] = v; }
        auto get(int i, int j) { return data[i * nc + j]; }
};

using MatI       = Array<int>;

constexpr auto M = 20;

auto           main() -> int
{
        int sz;
        std::cout << "Please enter the size of your matrix: ";
        std::cin >> sz;

        MatI m {{1, 2, 3, 4}};
}