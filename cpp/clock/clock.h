#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {

// TODO: add your solution here
class clock {
private:
    int hour;
    int minute;
public:
    clock(int hour, int minute) : hour(hour), minute(minute) {
        // hour = hour;
        // minute = minute;
    }

    static clock at(int hour, int minute) {
        int hour_rem = hour % 24;
        int min_rem = (minute % (24 * 60));

        if (hour_rem < 0) {
            hour_rem += 24;
        }

        if (min_rem < 0) {
            min_rem += (24 * 60);
        }

        int hour_carry = min_rem / 60;
        int minute_new = min_rem % 60;
        int hour_new = (hour_rem + hour_carry) % 24;

        return clock{hour_new, minute_new};
    }

    clock plus(int plus_minute) {
        int min_rem = (plus_minute % (24 * 60));

        if (min_rem < 0) {
            min_rem += (24 * 60);
        }

        int hour_carry = min_rem / 60;
        int minute_carry = min_rem % 60;
        int minute_new = minute + minute_carry;

        // another round of carries after addition...
        hour_carry += minute_new / 60;
        minute_new = minute_new % 60;

        int hour_new = (hour + hour_carry) % 24;

        return clock{hour_new, minute_new};
    }

    operator std::string() const {
        std::string hour_str{std::to_string(hour)};
        std::string minute_str{std::to_string(minute)};

        if (hour < 10) {
            hour_str = "0" + hour_str;
        }

        if (minute < 10) {
            minute_str = "0" + minute_str;
        }

        return hour_str + ":" + minute_str;
    }

    bool operator==(const clock& other_clock) const {
        return this->hour == other_clock.hour && this->minute == other_clock.minute;
    }

    bool operator!=(const clock& other_clock) const {
        return !(*this == other_clock);
    }
};

}  // namespace date_independent

#endif  // CLOCK_H