#include "nth_prime.h"

#include <stdexcept>
#include <cmath>

namespace nth_prime {

// TODO: add your solution here
int nth(int prime_index) {
    if (prime_index == 0) {
        throw std::domain_error("");
    }

    // intial value of curr_prime starts at 1 so temp_prime below is 2 (if temp_prime is 1 then it would return 1 is prime...)
    return nth_helper(prime_index, 1);
}

int nth_helper(int prime_index, int curr_prime) {
    if (prime_index == 0) {
        return curr_prime;
    }

    int temp_prime = curr_prime + 1;
    while (!is_prime(temp_prime)) {
        temp_prime++;
    }

    return nth_helper(prime_index - 1, temp_prime);
}

int is_prime(int num) {
    int sqrt_num = std::sqrt(num);

    if (sqrt_num * sqrt_num == num) {
        return false;
    }

    for (int i = 2; i <= sqrt_num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

}  // namespace nth_prime
