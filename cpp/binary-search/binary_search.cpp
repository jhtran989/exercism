#include "binary_search.h"

#include <stdexcept>
#include <string>
#include <iostream>

// for LLONG_MAX
#include <climits>

namespace binary_search {

// TODO: add your solution here

	std::size_t find(std::vector<int> data, int value) {
		std::size_t beg = 0;
		std::size_t end = data.size() - 1;
		std::size_t mid = (beg + end) / 2;
		std::size_t prev_mid = LLONG_MAX;

		// handle case where data is empty
		if (data.size() == 0) {
			throw std::domain_error("empty vector");
		}

		// IMPORTANT: fixed point when value is not found of form (beg, mid, end) = (X, X, Y) where beg and mid seems to have the same value so just need to check for Y
		while (true) {
			if (prev_mid == mid) {
				std::cout << "beg: " << beg << std::endl;
				std::cout << "mid: " << mid << std::endl;
				std::cout << "end: " << end << std::endl;

				if (value == data[end]) {
					return end;
				}
				else {
					throw std::domain_error("value " + std::to_string(value) + " not found");
				}
			}
			else if (value == data[mid]) {
				return mid;
			}
			else {
				if (value < data[mid]) {
					end = mid;
				}
				// value > data[mid]
				else {
					beg = mid;
				}

				prev_mid = mid;
				mid = (beg + end) / 2;
			}
		}
	}

}  // namespace binary_search
