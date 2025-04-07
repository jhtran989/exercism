#include "sublist.h"

#include <vector>
#include <iostream>

using std::cout;
using std::endl;

namespace sublist {

// TODO: add your solution here

// IMPORTANT: pass iterators by value (not by reference) so they do not mess up with other calls and recursion...

bool checkEqual(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>::iterator vec1Iter, std::vector<int>::iterator vec2Iter) {
    int vec1Size = vec1.end() - vec1Iter;
    int vec2Size = vec2.end() - vec2Iter;

    cout << "vec1 size: " << vec1Size << endl;
    cout << "vec2 size: " << vec2Size << endl;

    if (vec1Size != vec2Size) {
        return false;
    }

    while (vec1Iter != vec1.end() && vec2Iter != vec2.end() && *vec1Iter == *vec2Iter) {
        vec1Iter++;
        vec2Iter++;
    }

    if (vec1Iter != vec1.end() && vec2Iter != vec2.end()) {
        return false;
    } else {
        return true;
    }
}

// bool checkSublist(std::vector<int> vec1, std::vector<int> vec2, std::vector<int>::iterator vec1Iter, std::vector<int>::iterator vec2Iter) {
//     while (vec1Iter != vec1.end() && *vec1Iter != vec2.front()) {
//         vec1Iter++;
//     }

//     if (vec1Iter != vec1.end()) {
//         while (vec1Iter != vec1.end() && vec2Iter != vec2.end()) {
//             vec1Iter++;
//             vec2Iter++;
//         }

//         if (vec2Iter == vec2.end()) {
//             return true;
//         } else {
//             return false;
//         }
//     } else {
//         return false;
//     }
// }

bool checkSuperlist(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>::iterator vec1Iter, std::vector<int>::iterator vec2Iter) {
    // FIXME:
    cout << "first vec value: " << *vec1Iter << endl;
    cout << "second vec value: " << *vec2Iter << endl;

    while (vec1Iter != vec1.end() && *vec1Iter != vec2.front()) {
        vec1Iter++;
    }

    // TODO: add 1 for recursive call (no repeated checking) -- should be fine if over end() because if statement will return false if at end()
    std::vector<int>::iterator vec1IterCopy{vec1Iter + 1};
    std::vector<int>::iterator vec2IterCopy{vec2Iter};

    if (vec1Iter != vec1.end()) {
        while (vec1Iter != vec1.end() && vec2Iter != vec2.end() && *vec1Iter == *vec2Iter) {
            vec1Iter++;
            vec2Iter++;
        }

        if (vec2Iter == vec2.end()) {
            return true;
        } else {
            // FIXME:
            cout << "recursive..." << endl;

            // TODO: recursive
            return checkSuperlist(vec1, vec2, vec1IterCopy, vec2IterCopy);
        }
    } else {
        return false;
    }
}

List_comparison sublist(std::vector<int> vec1, std::vector<int> vec2) {
    if (vec1.empty() && vec2.empty()) {
        return List_comparison::equal;
    } else if (vec1.empty() && !vec2.empty()) {
        return List_comparison::sublist;
    } else if (!vec1.empty() && vec2.empty()) {
        return List_comparison::superlist;
    } else {
        auto vec1Iter = vec1.begin();
        auto vec2Iter = vec2.begin();

        // TODO: iterators passed by value so vec1Iter and vec2Iter do not change in between different if branches
        if (checkEqual(vec1, vec2, vec1Iter, vec2Iter)) {
            return List_comparison::equal;
        } else if (checkSuperlist(vec2, vec1, vec2Iter, vec1Iter)) {
            return List_comparison::sublist;
        } else if (checkSuperlist(vec1, vec2, vec1Iter, vec2Iter)) {
            return List_comparison::superlist;
        } else {
            return List_comparison::unequal;
        }
    }
}

}  // namespace sublist
