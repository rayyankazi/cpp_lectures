#include <iostream>

enum class Brands
{
        Invalid = -1,
        Huawei,
        Apple,
        Samsung,
        Count
};

enum class AppleProducts
{
        IPhone,
        IPad,
        MacBook,
        Airpods,
        Count
};

enum class SamsungProducts
{
        Galaxy,
        ZFold,
        Note,
        Count
};

auto print_brands()
{
        std::printf("Select from brands ");
        std::printf("(%d)%s,", static_cast<int>(Brands::Apple), "Apple");
        std::printf("(%d)%s,", static_cast<int>(Brands::Huawei), "Huawei");
        std::printf("(%d)%s: ", static_cast<int>(Brands::Samsung), "Samsung");
        std::printf("\n");
}

auto get_brand_from_user()
{
        int opt {};
        std::scanf("%d", &opt);
        if (opt < static_cast<int>(Brands::Huawei) || opt >= static_cast<int>(Brands::Count))
        {
                std::cout << "Invalid brand selected" << '\n';
                return Brands::Invalid;
        }

        return static_cast<Brands>(opt);
}

auto main() -> int
{
        do {
                print_brands();

                const auto ub = get_brand_from_user();
                switch (ub)
                {
                        case Brands::Huawei: std::printf("Huawei\n"); break;
                        case Brands::Apple: std::printf("Apple\n"); break;
                        case Brands::Samsung: std::printf("Samsung\n"); break;
                        default: std::printf("Invalid brand selected. Please try again.\n");
                }
        } while (true);
}
