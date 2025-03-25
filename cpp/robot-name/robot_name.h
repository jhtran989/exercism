#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <cstdlib>
#include <vector>
#include <set>

namespace robot_name {

// TODO: add your solution here
class robot {
private:
    std::string robot_name;
    std::set<std::string> previous_names;

    void get_new_name() {
        // Need to reset name (like when calling reset)
        robot_name = "";

        std::vector<char> letters{};
        std::vector<int> numbers{};

        // int seed = std::rand();
        // std::srand(seed);

        for (int i = 0; i < 2; i++) {
            letters.push_back(std::rand() % 26 + 'A');
        }
    
        for (int i = 0; i < 3; i++) {
            numbers.push_back(std::rand() % 10);
        }

        for (char letter: letters) {
            robot_name += letter;
        } 

        for (int num: numbers) {
            robot_name += std::to_string(num);
        }

        if (previous_names.find(robot_name) != previous_names.end()) {
            get_new_name();
        } else {
            previous_names.insert(robot_name);
        }
    }
public:
    robot() : robot_name(""), previous_names({}) {
        get_new_name();
    }

    std::string name() const {
        return robot_name;
    }

    void reset() {
        get_new_name();
    }
};

}  // namespace robot_name

#endif  // ROBOT_NAME_H