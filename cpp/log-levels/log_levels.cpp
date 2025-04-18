#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    return line.substr(line.find(":") + 2);
}

std::string log_level(std::string line) {
    // return the log level
    int beg = line.find("[");
    int end = line.find("]");
    return line.substr(beg + 1, end - beg - 1);
}

std::string reformat(std::string line) {
    // return the reformatted message
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
