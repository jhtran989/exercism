#if !defined(SAY_H)
#define SAY_H

#include <string>

namespace say {

// TODO: add your solution here
enum class decimal_place {
    hundred,
    thousand,
    million,
    billion,
};

enum class digit_english {
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
};

enum class ten_digit_english {
    ten,
    eleven,
    twelve,
    thirteen,
    fourteen,
    fifteen,
    sixteen,
    seventeen,
    eighteen,
    nineteen,
};

enum class tens_group_digit_english {
    twenty,
    thirty,
    forty,
    fifty,
    sixty,
    seventy,
    eighty,
    ninety,
};

std::string get_decimal_place_grouping(decimal_place curr_decimal_place_grouping);
std::string get_digit_english(digit_english curr_digit_english);
std::string get_ten_digit_english(ten_digit_english curr_ten_digit_english);
std::string get_tens_group_digit_english(tens_group_digit_english curr_tens_group_digit_english);
std::string in_english(long long num);

}  // namespace say

#endif  // SAY_H