#include "series.h"

#include <vector>
#include <string>
#include <deque>
#include <stdexcept>

namespace series {

// TODO: add your solution here
std::vector<std::string> slice(std::string input, int window) {
    if (window > static_cast<int>(input.length()) || window <= 0) {
        throw std::domain_error("");
    }

    std::deque<char> input_deque{input.begin(), input.begin() + window};
    std::vector<std::string> result{};

    result.push_back(std::string(input_deque.begin(), input_deque.end()));

    for (std::string::size_type i = window; i < input.length(); i++) {
        input_deque.pop_front();
        input_deque.push_back(input[i]);
        result.push_back(std::string(input_deque.begin(), input_deque.end()));
    }

    return result;
}

}  // namespace series
