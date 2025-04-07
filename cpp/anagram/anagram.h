#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

namespace anagram {

// TODO: add your solution here

std::string str_tolower(std::string input);

class anagram {
private:
    std::string input{};
public:
    anagram(std::string input) : input(input) {}

    std::set<std::string> matches(std::vector<std::string> match_vec) {
        std::set<std::string> result{};

        for (std::string match_str : match_vec) {
            // TODO: cannot be a set (need some way to store duplicate elements)
            // TODO: maybe store frequency with map
            // std::vector<char> input_check_set(input.begin(), input.end());
            std::map<char, int> input_check_set{};

            // TODO: remove case where exact same word is presented
            if (str_tolower(match_str) == str_tolower(input)) {
                continue;
            }

            for (char c : input) {
                c = tolower(c);

                if (input_check_set.find(c) == input_check_set.end()) {
                    input_check_set[c] = 1;
                } else {
                    input_check_set[c]++;
                }
            }

            bool check_all_chars{true};
            for (char c : match_str) {
                // TODO: lowercase the character
                c = tolower(c);

                if (input_check_set.find(c) != input_check_set.end()) {
                    // input_check_set.erase(c);
                    input_check_set[c]--;
                    if (input_check_set[c] == 0) {
                        input_check_set.erase(c);
                    }
                } else {
                    check_all_chars = false;
                }
            }

            if (input_check_set.empty() && check_all_chars) {
                result.insert(match_str);
            }
        }

        // FIXME:
        std::cout << "result:" << std::endl;
        for (std::string str : result) {
            std::cout << str << std::endl;
        }

        return result;
    }
};

}  // namespace anagram

#endif  // ANAGRAM_H