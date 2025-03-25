#include "reverse_string.h"

#include <string>
#include <algorithm>

namespace reverse_string {

// TODO: add your solution here
std::string reverse_string(std::string input_str) {
    std::string result{};

    copy(input_str.crbegin(), input_str.crend(), std::back_inserter(result));

    return result;
}

}  // namespace reverse_string
