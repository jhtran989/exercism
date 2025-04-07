#include "prime_factors.h"

#include <stdexcept>
#include <cmath>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

namespace prime_factors {

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

// changed from taking in int
bool is_prime(long long num) {
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

const std::vector<long long> of(long long num) {
    long long dividend = num;
    std::vector<long long> result{};

    // FIXME:
    cout << "num: " << num << endl;

    while (dividend != 1) 
    {
        int prime_index{1};

        // handle edge case where dividend is large prime (takes too long with nth...)
        if (is_prime(dividend)) {
            result.push_back(dividend);
            break;
        }

        while (true) {
            int prime = nth(prime_index);
            
            if (dividend % prime == 0) {
                dividend /= prime;
                result.push_back(prime);

                // FIXME:
                cout << "new dividend: " << dividend << endl;
                cout << "prime: " << prime << endl;

                break;
            }

            // FIXME:
            // cout << "outer prime index: " << prime_index << endl;
            // cout << "outer prime: " << prime << endl;

            prime_index++;
        }
    }

    return result;
    
}



}  // namespace prime_factors
