package armstrong_numbers

import "base:intrinsics"
//import "core:fmt"
import "core:math/bits"

/*
Generated using AI
*/
powInt :: proc(base: $T, exp: uint) -> T where intrinsics.type_is_integer(T) {
    result: T = 1
    b := base

    e := exp
    for e > 0 {
        if e & 1 == 1 {
            result *= b
        }
        b *= b
        e >>= 1
    }
    return result
}

/*
Copied from all-your-base exercise
*/
digitsFromBase10 :: proc(
    output_base: u128,
    base10: u128,
) -> (
    [dynamic]int,
    int,
) {
    highestBaseExp: u128 = 1
    highestBasePow := 0

    // NOTE: Modified to test for overflow
    // NOTE: Also fixed bug where number is clean multiple of base with
    // equality (like 10 for base 10)
    nextHighestBaseExp := highestBaseExp * output_base
    for nextHighestBaseExp <= base10 {
        highestBaseExp *= output_base
        highestBasePow += 1

        // Cannot assign nextHighestBaseExp directly here due to shadowing
        // (new variable because of :=)
        result, isOverflow := bits.overflowing_mul(highestBaseExp, output_base)

        // Stop looping if overflow occurred
        if (isOverflow) {
            break
        }

        nextHighestBaseExp = result
    }

    numDigits := highestBasePow + 1
    outputDigits := make([dynamic]int, 0, numDigits, context.allocator)

    currentBaseExp := highestBaseExp
    currentBasePow := highestBasePow
    currentBase10 := base10
    for currentIdx := 0; currentIdx < numDigits; currentIdx += 1 {
        currentDigit := currentBase10 / currentBaseExp
        assign_at(&outputDigits, currentIdx, cast(int)currentDigit)

        // Used %% for remainder instead of % for mod
        currentBase10 %%= currentBaseExp
        currentBaseExp /= output_base
        currentBasePow -= 1
    }

    return outputDigits, numDigits
}

is_armstrong_number :: proc(n: u128) -> bool {
    digitsList, numDigits := digitsFromBase10(10, n)
    defer delete(digitsList)

    // Debug print
    // fmt.println("digits list: ", digitsList[:])
    // fmt.println("num digits: ", numDigits)

    numDigitsUnsigned := cast(uint)numDigits

    // Handle special case if n is zero
    if (n == 0) {
        return true
    }

    armstrongSum: u128 = 0
    for digit in digitsList {
        armstrongSum += powInt(cast(u128)digit, numDigitsUnsigned)
    }

    return n == armstrongSum
}
