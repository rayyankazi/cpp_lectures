
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Item
{};

struct Inventory
{
        using SearchPredicate = std::function<bool(const Item&)>;
        using Items           = std::vector<Item>;
        using ItemPtr         = Items::iterator;

        Items items {};

        auto  find_item(SearchPredicate const& pred)
        {
                // this is equivalent

                auto pitem = std::find_if(items.begin(), items.end(), pred);
                if (pitem != items.end()) { return pitem; }

                return ItemPtr {};

                // to this
                // ItemPtr pitem {};
                // for (auto i = 0; i < items.size(); i += 1)
                // {
                //         if (pred(items[i]))
                //         {
                //                 pitem = items.begin() + i;
                //                 break;
                //         }
                // }

                // return pitem;
        }
};

auto main() -> int {}