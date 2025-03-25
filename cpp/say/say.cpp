#include "say.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

using std::cout;
using std::endl;

namespace say {

// digit_english digit_to_english(int digit) {

// }

// std::string digit_to_string(digit_english digit_english) {
//     return std::to_string(static_cast<int>(digit_english));
// }

std::string get_decimal_place_grouping(decimal_place curr_decimal_place_grouping) {
    switch (curr_decimal_place_grouping)
    {
        case decimal_place::hundred:
            return "hundred";
        case decimal_place::thousand:
            return "thousand";
        case decimal_place::million:
            return "million";
        case decimal_place::billion:
            return "billion";
        default:
            throw std::domain_error("wrong enum decimal_place");
    }
}

std::string get_digit_english(digit_english curr_digit_english) {
    switch (curr_digit_english)
    {
        case digit_english::zero:
            return "zero";
        case digit_english::one:
            return "one";
        case digit_english::two:
            return "two";
        case digit_english::three:
            return "three";
        case digit_english::four:
            return "four";
        case digit_english::five:
            return "five";
        case digit_english::six:
            return "six";
        case digit_english::seven:
            return "seven";
        case digit_english::eight:
            return "eight";
        case digit_english::nine:
            return "nine";
        default:
            throw std::domain_error("wrong enum digit_english");
    }
}

std::string get_ten_digit_english(ten_digit_english curr_ten_digit_english) {
    switch (curr_ten_digit_english)
    {
        case ten_digit_english::ten:
            return "ten";
        case ten_digit_english::eleven:
            return "eleven";
        case ten_digit_english::twelve:
            return "twelve";
        case ten_digit_english::thirteen:
            return "thirteen";
        case ten_digit_english::fourteen:
            return "fourteen";
        case ten_digit_english::fifteen:
            return "fifteen";
        case ten_digit_english::sixteen:
            return "sixteen";
        case ten_digit_english::seventeen:
            return "seventeen";
        case ten_digit_english::eighteen:
            return "eighteen";
        case ten_digit_english::nineteen:
            return "nineteen";
        default:
            throw std::domain_error("wrong enum ten_digit_english");
    }
}

std::string get_tens_group_digit_english(tens_group_digit_english curr_tens_group_digit_english) {
    switch (curr_tens_group_digit_english)
    {
        case tens_group_digit_english::twenty:
            return "twenty";
        case tens_group_digit_english::thirty:
            return "thirty";
        case tens_group_digit_english::forty:
            return "forty";
        case tens_group_digit_english::fifty:
            return "fifty";
        case tens_group_digit_english::sixty:
            return "sixty";
        case tens_group_digit_english::seventy:
            return "seventy";
        case tens_group_digit_english::eighty:
            return "eighty";
        case tens_group_digit_english::ninety:
            return "ninety";
        default:
            throw std::domain_error("wrong tens_group_digit_english");
    }
}

// TODO: add your solution here
std::string in_english(long long num) {
    if (num < 0 || num > 999'999'999'999) {
        throw std::domain_error("");
    }

    std::string result{};

    int three_digit{};
    long long remainder{num};
    int decimal_place_index{0};
    bool initial_grouping{true};
    std::string three_digit_str{};

    // FIXME:
    cout << endl;
    cout << "num: " << num << endl;

    do
    {
        // IMPORTANT: need to reset after each iter
        three_digit_str = "";

        three_digit = remainder % 1000;
        remainder = remainder / 1000;
        int three_digit_copy = three_digit;

        // FIXME: redundant adding space
        // add spacing after initial group
        // IMPORTANT: also only if remainder is not zero
        // if (!initial_grouping && remainder != 0 && three_digit != 0) {
        //     three_digit_str += " ";
        // }

        // FIXME:
        cout << "intermediate result: " << result << endl;
        cout << "three digits: " << three_digit << endl;
        cout << "remainder: " << remainder << endl;

        std::stack<int> digits_stack;

        for (int i = 0; i < 3; i++) {
            int digit = three_digit % 10;
            three_digit /= 10;

            digits_stack.push(digit);
        }

        decimal_place place = static_cast<decimal_place>(decimal_place_index);

        int digit{digits_stack.top()};
        if (digit != 0)
        {
            digit_english curr_digit_english = static_cast<digit_english>(digit);
            three_digit_str += get_digit_english(curr_digit_english) + " hundred";
        }

        digits_stack.pop();

        int tens_digit{digits_stack.top()};
        digits_stack.pop();
        int ones_digit{digits_stack.top()};
        digits_stack.pop();

        // FIXME:
        cout << "hundred: " << digit << endl;
        cout << "ten: " << tens_digit << endl;
        cout << "one: " << ones_digit << endl;

        // IMPORTANT: add space BEFORE processing tens/ones digit
        if (digit != 0 && (tens_digit != 0 || ones_digit != 0)) {
            // IMPORTANT: add space after "hundred" for nonzero tens and ones digit
            three_digit_str += " ";
        }

        // IMPORTANT: need to subtract 2 (index 0 -> twenty (2 as tens digit))
        if (tens_digit != 0 && ones_digit != 0) {
            if (tens_digit == 1) {
                three_digit_str += get_ten_digit_english(static_cast<ten_digit_english>(ones_digit));
            } else {
                three_digit_str += get_tens_group_digit_english(static_cast<tens_group_digit_english>(tens_digit - 2))
                + "-" + get_digit_english(static_cast<digit_english>(ones_digit));
            }
        } else if (tens_digit != 0 && ones_digit == 0) {
            if (tens_digit == 1) {
                three_digit_str += get_ten_digit_english(ten_digit_english::ten);
            } else {
                three_digit_str += get_tens_group_digit_english(static_cast<tens_group_digit_english>(tens_digit - 2));
            }
        // IMPORTANT: include case where ones digit is zero
        } else if (tens_digit == 0) {
            // edge case of pure single digit (handle 0 first)
            if (remainder == 0 && three_digit_copy == 0) {
                // FIXME:
                cout << "three digit zero check: " << three_digit << endl;
                three_digit_str += get_digit_english(static_cast<digit_english>(ones_digit));
            } else if (ones_digit > 0) {
                three_digit_str += get_digit_english(static_cast<digit_english>(ones_digit));
            }
        } 

        // make sure not empty
        if (decimal_place_index != 0 && three_digit_copy != 0) {
            // three_digit_str += " " + get_decimal_place_grouping(static_cast<decimal_place>(decimal_place_index));
            three_digit_str += " " + get_decimal_place_grouping(place);
        }

        if (initial_grouping) {
            initial_grouping = false;
        } 

        // commented out above because of this (spacing between iters)
        // IMPORTANT: need to add space in between subsequent iters (and previous part is not empty)
        if (decimal_place_index != 0 && result != "") {
            result = three_digit_str + " " + result;
        } else {
            result = three_digit_str + result;
        }
        
        three_digit = remainder;
        decimal_place_index++;

        // FIXME:
        cout << "|" << three_digit_str << "|" << endl;
        cout << "|" << result << "|" << endl;
    } while (three_digit != 0);
    
    return result;
}

}  // namespace say
