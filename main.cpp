#include <iostream>
#include <string_view>

/*
        Return Type
        Produce Value
        Invoke
        Parameters (Definition)
        Arguments (Invoking)
*/

auto say_hello() { std::cout << "Hello World" << '\n'; }
auto say(std::string_view greeting) { std::cout << greeting << '\n'; }
auto add(int x, int y) -> int { return x + y; }

// Exercises
// 1. Write a function that takes two string_views (a, b) and returns a string (ab) that's a join of the two.
// 2. Write a function that takes three floats and returns the average of the three numbers.

int  main()
{
        say("Hello World");
        say("Namaste");
        say("Vanakkam");
        std::cout << add(3, 4) << '\n';
}