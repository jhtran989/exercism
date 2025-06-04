#include "leap.h"

namespace leap {

// TODO: add your solution here

	bool is_leap_year(int year) {
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}

}  // namespace leap
