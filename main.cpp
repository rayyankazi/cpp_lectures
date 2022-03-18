#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

auto main() -> int
{
        // RAM - Random Access Memory (Volatile Storage, Memory)
        // [||||||...|||] -> 1 byte per cell
        // 1 byte = 8 bits (binary digit)
        // 1024 bytes = 1KB
        // 1024 KB = 1MB
        // 1024 MB = 1GB
        // 1024 GB = 1TB
        int     x {4};           // 4 bytes = 32 bits
        int16_t x16 {};          // 2 bytes = 16 bits
        auto    p {&x16};        // p is a variable that holds the address or location of x16
        // p is therefore called a pointer (variable) to x16

        {
                auto x {46};
                auto px {&x};        // address of an integer

                auto y {3.f};
                auto py {&y};
                auto yy {4.13f};
                py = &yy;

                auto               z {"Google"};
                auto               pz {&z};

                // Array to Pointer Decay
                // An array's name is just a pointer to the beginning of the array.
                std::array<int, 3> ax {1, 2, 3};
                std::printf("%p -> %d\n", ax.begin() + 0, *(ax.begin() + 0));
                std::printf("%p -> %d\n", ax.begin() + 1, *(ax.begin() + 1));
                std::printf("%p -> %d\n", ax.begin() + 2, *(ax.begin() + 2));

                // NOTE!!!!!: You cannot take the address of a literal.
                // Example: auto px = &4; // INCORRECT
                // Example: auto px = &4.45f; // INCORRECT
                // Example: auto px = &"hello world"; // INCORRECT

                constexpr int      N = 4;

                // NOTE!!!! end() will give the address of the immediate next address from the last item in array/vector
                std::array<int, N> a {1, 2, 3, 4};
                // auto               p   = a.begin();          // address of first item in array
                // std::printf("%p\n", p); // print the address of item pointed to by p
                // p += 1;
                // std::printf("%p\n", p); // print the address of item pointed to by p
                // p = std::next(p);
                // std::printf("%p\n", p); // print the address of item pointed to by p

                auto               q = a.end() - 1;        // address of last item in array
                std::printf("%p -> %d\n", q, *q);
                q -= 1;
                std::printf("%p -> %d\n", q, *q);

                // auto               tmp = -1;

                // Dereferencing -> Get the item/value at address
                // Referencing -> Get the address of item/variable
                // Pointer Arithmetic

                // while (p < q)
                // {
                //         tmp = *p; // Dereference p and copy item into tmp, p = &a[0]
                //         *p = *q; // *q -> gets the item from the address in q, *p <- *q => a = {4, 2, 3, 4}
                //         p += 1; // move the p forward -> pointer arithmetic

                //         *q = tmp; // a = {4, 2, 3, 1}
                //         q -= 1; // move the q backward
                // }

                // std::reverse(a.begin(), a.end());
                std::for_each(a.begin(), a.end(), [](const auto v) { std::cout << v << '\n'; });
                // a => {4, 3, 2, 1} -> Reversing the array a
        }
}