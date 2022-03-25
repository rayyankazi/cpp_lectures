// T2 - Beginning C++17
// Chapter 3, Pg. 77 - 80
// Chapter 11, Pg. 386

// Enumerations and Structures

#include <array>
#include <iostream>

// Colors
enum class Color
{
        Red,
        Green,
        Blue,
        Count
};

// Properties
enum class ColorProperty
{
        Saturation,
        Brightness,
        Value,
};

constexpr std::array<std::string_view, static_cast<int>(Color::Count)> COLORS {"Red", "Green", "Blue"};

auto                                                      get_color(Color c) { return COLORS[static_cast<int>(c)]; }

auto                                                      main() -> int { std::cout << get_color(Color::Green) << '\n'; }