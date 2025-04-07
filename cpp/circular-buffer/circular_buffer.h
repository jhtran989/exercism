#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <deque>
#include <stdexcept>

namespace circular_buffer {

// TODO: add your solution here
template <typename T>
class circular_buffer {
private:
    int size{};
    int occupied{0};
    std::deque<T> buffer{};
public:
    circular_buffer(int size) : size(size) {}

    T read() {
        if (buffer.empty()) {
            throw std::domain_error("Reading empty buffer...");
        }

        T value_read = buffer.front();
        buffer.pop_front();

        occupied--;

        return value_read;
    }

    void write(T value) {
        if (occupied == size) {
            throw std::domain_error("Writing full buffer...");
        }

        buffer.push_back(value);
        occupied++;
    }

    void clear() {
        buffer.clear();
        occupied = 0;
    }

    void overwrite(T value) {
        if (occupied == size) {
            // T _ (so that it shows read() returns something...)
            read();
        } 

        write(value);
    }
};

}  // namespace circular_buffer

#endif  // CIRCULAR_BUFFER_H