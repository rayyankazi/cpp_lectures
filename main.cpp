#include "matrix.hpp"

using MatI       = Matrix<int>;

constexpr auto M = 20;

auto           main() -> int
{
        MatI m {{1, 2, 3, 4}};
        m.reshape(2, 2);
        const auto [nr, nc] = m.shape();
        std::printf("shape: (%d, %d)\n", nr, nc);

        for (auto i = 0; i < nr; i++)
        {
                for (auto j = 0; j < nc; j++) { m(i, j)++; }
        }

        // print the matrix
        m.show();

        const MatI n {{1, 2, 3, 4, 5}};
        n(0, 1);
}