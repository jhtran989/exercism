#pragma once

#include <vector>

namespace sublist {

// TODO: add your solution here

enum class List_comparison {
    equal,
    sublist,
    superlist,
    unequal,
};

bool checkEqual(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>::iterator vec1Iter, std::vector<int>::iterator vec2Iter);

bool checkSuperlist(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>::iterator vec1Iter, std::vector<int>::iterator vec2Iter);

List_comparison sublist(std::vector<int> vec1, std::vector<int> vec2);

}  // namespace sublist
