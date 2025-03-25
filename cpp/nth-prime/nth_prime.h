#if !defined(NTH_PRIME_H)
#define NTH_PRIME_H

namespace nth_prime {

// TODO: add your solution here
int nth(int prime_index);

int nth_helper(int prime_index, int curr_prime);

int is_prime(int num);

}  // namespace nth_prime

#endif  // NTH_PRIME_H