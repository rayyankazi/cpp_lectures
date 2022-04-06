#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

/*
        matrix.hpp provides a simple to use matrix class. It's by no means optimized for performance, but aimed at educational use for convenience.
        Any use of this header file must include this comment along with the link from where this file is obtained.


        Author: Chatrapathi Akula
        Date: 06.04.2022
*/
#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

template<typename T>
class Matrix
{
      public:
        using SelfRef = Matrix<T>&;

      private:
        SelfRef        self;
        std::vector<T> data;
        int            nr, nc;

      public:
        Matrix(int nr, int nc) : self {*this}, data(nr * nc), nr {nr}, nc {nc} {}
        Matrix(std::initializer_list<T> val) : self {*this}, data {val}, nr {1}, nc {static_cast<int>(val.size())} {}

        /// @brief Get/Set element at location (i, j).
        auto operator()(const int i, const int j) -> T& { return data[i * nc + j]; }
        auto operator()(const int i, const int j) const -> const T& { return data[i * nc + j]; }

        /// @brief Changes the shape of the matrix to the new shape.
        /// @param nr No. of rows
        /// @param nc No. of columns
        /// @returns Returns a reference to self.
        auto reshape(int nr, int nc) -> SelfRef
        {
                if (nr * nc == size())
                {
                        this->nr = nr;
                        this->nc = nc;
                }

                return *this;
        }

        /// @brief Computes the no. of elements in the matrix.
        auto size() const { return nr * nc; }

        /// @brief Returns the shape of the matrix.
        auto shape() const { return std::make_pair(nr, nc); }

        /// @brief Display the matrix in a neatly formatted way.
        auto show() const
        {
                for (auto i = 0; i < nr; i++)
                {
                        std::printf("[");
                        for (auto j = 0; j < nc; j++) { std::printf(" %8d ", self(i, j)); }
                        std::printf("]\n");
                }
        }
};

#endif