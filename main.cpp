#include <iostream>

enum class Products
{
        Invalid = -1,
        productsStart,

        samsungStart,
        SamsungGalaxy,
        SamsungNote,
        SamsungZFold,
        samsungStop,

        appleStart,
        AppleIPhone,
        AppleIPad,
        AppleMacBook,
        appleStop,

        productsEnd,
};

auto is_product(Products p)
{
        return p > Products::productsStart && p < Products::productsEnd;
}

auto is_apple_product(Products p)
{
        return p > Products::appleStart && p < Products::appleStop;
}

auto main() -> int
{
        int opt {7};
        std::cout << is_apple_product(static_cast<Products>(opt)) << '\n';
}
