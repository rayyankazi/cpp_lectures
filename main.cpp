#include <algorithm>
#include <cmath>        // pow, fmod
#include <functional>
#include <iostream>
#include <optional>
#include <vector>

/// Calc is an extensible calculator that in addition to performing the basic operations
/// enables the user to add and perform new, but predefined, operations.
namespace calc
{

        // List of arithmetic operations available in the calculator.
        enum class Operations
        {
                Invalid = -1,
                Addition,
                Subtraction,
                Multiplication,
                Division,
                Power,
                Remainder,
                Count
        };

        /// @brief Checks if the given operation is valid.
        ///
        /// @returns true if op > Invalid and op < Count.
        auto           is_valid_op(Operations op) { return op > Operations::Invalid && op < Operations::Count; }

        /// @brief Checks if the given operation is a default.
        ///
        /// @returns true if op is not Power and Remainder operation.
        auto           is_default_op(Operations op) { return (op != Operations::Power) && (op != Operations::Remainder); }

        /// @brief Returns the name of the given operation as string_view.
        constexpr auto get_op_name(Operations op)
        {
                // OP_NAMES holds the names of the operations available.
                constexpr std::string_view OP_NAMES[static_cast<int>(Operations::Count)] = {
                    [static_cast<int>(Operations::Addition)]       = "Addition",
                    [static_cast<int>(Operations::Subtraction)]    = "Subtraction",
                    [static_cast<int>(Operations::Multiplication)] = "Multiplication",
                    [static_cast<int>(Operations::Division)]       = "Division",
                    [static_cast<int>(Operations::Power)]          = "Power",
                    [static_cast<int>(Operations::Remainder)]      = "Remainder",
                };

                if (!is_valid_op(op)) { return std::string_view {""}; }

                return OP_NAMES[static_cast<int>(op)];
        }

        // An Instruction represents the arithmetic operation that a calculator can perform.
        // Every instruction has the following structure <Operation Function>.
        struct Instruction
        {
                using binary_fn = std::function<float(float, float)>;

                Operations op;
                binary_fn  fn;

                Instruction() : op {Operations::Invalid}, fn {nullptr} {}
                Instruction(Operations op, binary_fn fn) : op {op}, fn {fn} {}
        };

        // An extensible calculator that in addition to performing the basic operations
        // enables the user to add and perform new, but predefined, operations.
        struct Calculator
        {
                using Instructions = std::vector<Instruction>;

                enum class Error
                {
                        Ok,
                        InvalidOperationSelected,
                        OperationAlreadyExists,
                };

                Instructions instructions;

                Calculator()
                {
                        instructions.reserve(static_cast<int>(Operations::Count));        // reserve space for the operations we have

                        // add our default operations
                        instructions.emplace_back(Operations::Addition, [](float lhs, float rhs) { return lhs + rhs; });
                        instructions.emplace_back(Operations::Subtraction, [](float lhs, float rhs) { return lhs - rhs; });
                        instructions.emplace_back(Operations::Multiplication, [](float lhs, float rhs) { return lhs * rhs; });
                        instructions.emplace_back(Operations::Division, [](float lhs, float rhs) { return lhs / rhs; });
                }

                /// @brief Computes the result of the given operation `lhs op rhs`.
                ///
                /// @returns If the selected operation does not exist, then an empty optional is returned.
                auto compute(Operations op, float lhs, float rhs) -> std::optional<float>
                {
                        // find the given operation in our store
                        const auto pinstr = std::find_if(instructions.begin(), instructions.end(), [op](const auto& i) { return i.op == op; });

                        // compute and return the result if operation is found
                        if (pinstr != instructions.end()) { return {pinstr->fn(lhs, rhs)}; }

                        return {};
                }

                /// @brief Append new operation to the store.
                ///
                /// @returns Error::Ok - if operation doesn't exist and is valid.
                /// Error::OperationAlreadyExists - if operation already exists.
                /// Error::InvalidOperationSelected - if operation is invalid.
                auto add_new_op(Operations op)
                {
                        // check if valid operation
                        if (!is_valid_op(op)) { return Error::InvalidOperationSelected; }

                        // check if op is default op
                        if (!is_default_op(op))
                        {
                                // check if already exists in our store
                                if (std::none_of(instructions.begin(), instructions.end(), [&](const auto& i) { return i.op == op; }))
                                {
                                        // add the requested operation
                                        if (op == Operations::Power)
                                        {
                                                instructions.emplace_back(op, [](float lhs, float rhs) { return std::pow(lhs, rhs); });
                                        }
                                        else if (op == Operations::Remainder)
                                        {
                                                instructions.emplace_back(op, [](float lhs, float rhs) { return std::fmod(lhs, rhs); });
                                        }

                                        return Error::Ok;
                                }
                        }

                        return Error::OperationAlreadyExists;
                }

                /// @brief Display the list of operations available to the user.
                auto print_instructions()
                {
                        std::cout << "List of operations: " << '\n';
                        for (auto& i : instructions)
                        {
                                const auto* name = get_op_name(i.op).data();
                                std::printf("(%d) %s\n", static_cast<int>(i.op), name);
                        }
                }
        };

        constexpr std::string_view InvalidOperationSelectedMessage = "Invalid operation selected. Please try again.\n";

        /// CalculatorUI handles input and output for the console user interface, dispatching the correct operations to the calculator
        /// and displaying the results to the user.
        struct CalculatorUI
        {
                enum class Signal
                {
                        Ok,
                        InvalidOption,
                        Quit,
                };

                enum class Option
                {
                        Compute = 'c',
                        NewOp   = 'n',
                        Quit    = 'q',
                };

                Calculator calc;

                CalculatorUI() : calc {} {}

                /// @brief Returns a function that handles the users selected option.
                auto user_option_handler() -> std::function<Signal()>
                {
                        char opt {};
                        std::cout << "Select function (c)Compute (n)New Operation (q)Quit: ";
                        std::cin >> opt;

                        if (opt == static_cast<char>(Option::NewOp))
                        {
                                return [this]() {
                                        int opt {};
                                        std::cout << "(4)Power, (5)Remainder: ";
                                        std::cin >> opt;

                                        const auto err = calc.add_new_op(static_cast<Operations>(opt));
                                        if (err != Calculator::Error::Ok && err != Calculator::Error::InvalidOperationSelected)
                                        {
                                                std::cout << InvalidOperationSelectedMessage;
                                                return Signal::InvalidOption;
                                        }

                                        return Signal::Ok;
                                };
                        }

                        if (opt == static_cast<char>(Option::Compute))
                        {
                                return [this]() {
                                        calc.print_instructions();

                                        int op {};
                                        std::cin >> op;

                                        const auto uop = static_cast<Operations>(op);        // user selected operation
                                        if (!is_valid_op(uop))
                                        {
                                                std::cout << InvalidOperationSelectedMessage;
                                                return Signal::InvalidOption;
                                        }

                                        // get numbers from user
                                        float lhs {}, rhs {};
                                        std::cout << "Enter arguments (a b): ";
                                        std::cin >> lhs;
                                        std::cin >> rhs;

                                        // compute result and display to user
                                        const auto res = calc.compute(uop, lhs, rhs);
                                        if (res) { std::cout << "Result = " << res.value() << '\n'; }

                                        return Signal::Ok;
                                };
                        }

                        if (opt == static_cast<char>(Option::Quit))
                        {
                                return [this]() { return Signal::Quit; };
                        }

                        return [this]() { return Signal::InvalidOption; };
                }

                auto run()
                {
                        std::cout << "Calc v0.1.\n";
                        do {
                                const auto handler = user_option_handler();
                                if (handler() == CalculatorUI::Signal::Quit) { break; }
                        } while (true);
                }
        };
}        // namespace calc

auto main() -> int
{
        calc::CalculatorUI calc_ui {};
        calc_ui.run();
}