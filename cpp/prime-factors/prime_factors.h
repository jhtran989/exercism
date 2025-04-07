#if !defined(PRIME_FACTORS_H)
#define PRIME_FACTORS_H

#include <vector>

namespace prime_factors {

// TODO: add your solution here
int nth(int prime_index);

int nth_helper(int prime_index, int curr_prime);

bool is_prime(long long num);

const std::vector<long long> of(long long num);

}  // namespace prime_factors

#endif  // PRIME_FACTORS_H