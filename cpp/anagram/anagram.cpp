#include "anagram.h"

namespace anagram {

// TODO: add your solution here

std::string str_tolower(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return input;
}

}  // namespace anagram
