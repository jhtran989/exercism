package leap

import "core:fmt"

is_leap_year :: proc(year: int) -> bool {
    if year % 400 == 0 {
        // Handle special century case every 400 years
        return true
    } else if year % 4 == 0 && year % 100 != 0 {
        // Handle regular case every 4 years
        return true
    }

    return false
}
