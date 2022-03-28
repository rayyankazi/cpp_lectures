#include <algorithm>
#include <iostream>
#include <vector>

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

std::vector<std::string> PRODUCT_NAMES {
        "",
        "",
        "Galaxy",
        "Note",
        "ZFold",
        "",
        "",
        "iPhone",
};

constexpr auto NUM_BRANDS = 3;

struct Item
{
        Products    product;
        int         stock;
        float       price;
        std::string name;
        std::string brand;

        Item() = default;
        Item(Products p, int num_stock, float price, std::string_view name) : product {p}, stock {num_stock}, price {price}, name {name} {}
};

auto is_product(Products p) { return p > Products::productsStart && p < Products::productsEnd; }

auto is_apple_product(Products p) { return p > Products::appleStart && p < Products::appleStop; }

auto get_product_details()
{
        Item item {};

        int  product_id {};

        std::cout << "Select product: ";
        std::cin >> product_id;
        if (is_product(static_cast<Products>(product_id)))
        {
                std::cout << "Enter stock: ";
                std::cin >> item.stock;
                std::cout << "Enter price: ";
                std::cin >> item.price;
                std::cout << "Enter name: ";
                std::cin >> item.name;
        }

        return item;
}

using Items = std::vector<Item>;

auto search_item(Items& items)
{
        char sopt {};
        std::cout << "(n)Search by Name, (p)Search by Product: ";
        std::cin >> sopt;
        if (sopt == 'n')
        {
                std::string name {};
                std::cout << "Enter product name: ";
                std::cin >> name;
                return std::find_if(items.begin(), items.end(), [&](const Item& item) { return item.name == name; });
        }

        return items.end();        // if nothing is found then return the end of the items
}

auto main() -> int
{
        Items items {};

        char opt {};
        do {
                std::cout << "(a)Add, (r)Remove, (e)Edit, (s)Search: ";
                std::scanf(" %c", &opt);

                if (opt == 'a')
                {
                        // adding item
                        const auto item = get_product_details();
                        items.push_back(item);
                }
                else if (opt == 's')
                {
                        const auto pitem = search_item(items);
                        std::cout << pitem->name << '\n';
                }
                else if (opt == 'e')
                {
                        //
                        auto pitem = search_item(items);
                        std::cin >> pitem->name;
                }
                else
                {
                        // invalid user option
                        std::cout << "Invalid option selected. Please try again." << '\n';
                        break;
                }
        } while (true);
}
