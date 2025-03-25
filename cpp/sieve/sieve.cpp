#include "sieve.h"

#include <vector>

namespace sieve {

// TODO: add your solution here

std::vector<int> primes(int upper) {
    std::vector<int> result{};
    // const std::size_t array_len = upper + 1;
    std::vector<bool> prime_marks(upper + 1, true);

    // NOT NEEDED
    // prime_marks[0] = false;
    // prime_marks[1] = false;

    if (upper < 2) {
        return result;
    }

    // FIXME: don't use size_type (unsigned) because upper is int (signed)
    //typedef std::vector<int>::size_type vec_int_size;
    for (int i = 2; i <= upper; i++)
    {
        for (int j = 2 * i; j <= upper; j += i) {
            prime_marks[j] = false;
        }
    }

    for (int i = 2; i <= upper; i++) {
        if (prime_marks[i]) {
            result.push_back(i);
        }
    }

    return result;
}

}  // namespace sieve
