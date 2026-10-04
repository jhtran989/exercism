package clock

import "core:fmt"

// Implement this struct
Clock :: struct {
    hour:   int,
    minute: int,
}

updateMinutes :: proc(clock: ^Clock, minutes: int) {
    clockHour := clock.hour

    // Handle addition/subtraction of minutes (with sign)
    // Do NOT use %% because of potential negative carry if sign is negative
    totalMinute := clock.minute + minutes
    clockMinute := totalMinute % 60
    clockCarryHour := totalMinute / 60

    // Handle extra negative carry to hour
    if (clockMinute < 0) {
        clockMinute += 60
        clockCarryHour -= 1
    }

    // Handle carry hour from minute and preserve sign
    clockHour = (clockHour + clockCarryHour) %% 24

    clock.hour = clockHour
    clock.minute = clockMinute

    // FIXME:
    // fmt.printfln("updateMinutes minutes: %v", minutes)
}

create_clock :: proc(hour, minute: int) -> Clock {
    // Use %% for positive remainder
    clockHour := hour %% 24

    // Initialize with 0 minutes
    clock := Clock {
        hour   = clockHour,
        minute = 0,
    }

    // Add minute to the initial clock
    updateMinutes(&clock, minute)

    // // FIXME:
    // fmt.printfln("hour: %v", hour)
    // fmt.printfln("minute: %v", minute)
    // fmt.println(clock)

    return clock
}

to_string :: proc(clock: Clock) -> string {
    // Make sure to allocate string since test will try and delete it
    return fmt.aprintf("%02d:%02d", clock.hour, clock.minute)
}

add :: proc(clock: ^Clock, minutes: int) {
    updateMinutes(clock, minutes)
}

subtract :: proc(clock: ^Clock, minutes: int) {
    // Add negative sign to subtract
    updateMinutes(clock, -minutes)
}

equals :: proc(clock1, clock2: Clock) -> bool {
    return clock1.hour == clock2.hour && clock1.minute == clock2.minute
}
