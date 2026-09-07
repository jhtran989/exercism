package all_your_base

import "core:fmt"
import "core:slice"

Error :: enum {
    None,
    Invalid_Input_Digit,
    Input_Base_Too_Small,
    Output_Base_Too_Small,
    Unimplemented,
}

/*
UPDATE: Due to testing framework, it is expected for the main function rebase() below to return []int from a DYNAMIC ARRAY because of the explicit call to delete the returned []int in all_your_base_test.odin test cases. This means creating a global fixed array below causes a bad free warning since it was NOT dynamically allocated with make() -- trying to delete something that was not allocated gives a warning instead of silently continuing.
*/

// // Needed since []int is returned in rebase() but number of digits is determined at runtime
// MAX_DIGITS :: 32

// // Since a dynamic array is returned below in digitsFromBase10(), need some fixed array that exists beyond the scope of rebase() below to return []int (cannot return slice from dynamic array safely in same scope where it is deleted)
// // Initialized to all 0s at runtime
// @(thread_local)
// outputDigitsGlobal: [MAX_DIGITS]int

isBaseNegative :: proc(base: int) -> bool {
    return base < 0
}

isBaseSmallNonNegative :: proc(base: int) -> bool {
    return base == 0 || base == 1
}

isBaseSmall :: proc(base: int) -> bool {
    return isBaseNegative(base) || isBaseSmallNonNegative(base)
}

/*
Int math pow (not part of core:math)

Does NOT account for negative exponents or overflow
*/
powInt :: proc(base: int, pow: int) -> int {
    output := 1
    for _ in 0 ..< pow {
        output *= base
    }

    return output
}

/*
Assume both input_base and digits are valid 
*/
convertToBase10 :: proc(input_base: int, digits: []int) -> int {
    base10 := 0

    // digits are in REVERSE order (highest digit first)
    // Need to reverse the digits to index from smallest to largest digit
    digitsInOrder := make([]int, len(digits))
    defer delete(digitsInOrder)

    copy(digitsInOrder, digits)
    slice.reverse(digitsInOrder)

    for digit, pow in digitsInOrder {
        base10 += digit * powInt(input_base, pow)
    }

    return base10
}

digitsFromBase10 :: proc(output_base: int, base10: int) -> [dynamic]int {
    highestBaseExp := 1
    highestBasePow := 0

    for highestBaseExp * output_base < base10 {
        highestBaseExp *= output_base
        highestBasePow += 1
    }

    numDigits := highestBasePow + 1
    outputDigits := make([dynamic]int, 0, numDigits, context.allocator)

    currentBaseExp := highestBaseExp
    currentBasePow := highestBasePow
    currentBase10 := base10
    for currentIdx := 0; currentIdx < numDigits; currentIdx += 1 {
        currentDigit := currentBase10 / currentBaseExp
        assign_at(&outputDigits, currentIdx, currentDigit)

        // Used %% for remainder instead of % for mod
        currentBase10 %%= currentBaseExp
        currentBaseExp /= output_base
        currentBasePow -= 1
    }

    return outputDigits
}

// digitsFromBase10 :: proc(output_base: int, base10: int) -> int {
//     highestBaseExp := 1
//     highestBasePow := 0

//     for highestBaseExp * output_base < base10 {
//         highestBaseExp *= output_base
//         highestBasePow += 1
//     }

//     numDigits := highestBasePow + 1

//     currentBaseExp := highestBaseExp
//     currentBasePow := highestBasePow
//     currentBase10 := base10
//     for currentIdx := 0; currentIdx < numDigits; currentIdx += 1 {
//         currentDigit := currentBase10 / currentBaseExp
//         outputDigitsGlobal[currentIdx] = currentDigit

//         // Used %% for remainder instead of % for mod
//         currentBase10 %%= currentBaseExp
//         currentBaseExp /= output_base
//         currentBasePow -= 1
//     }

//     return numDigits
// }

rebase :: proc(
    input_base: int,
    digits: []int,
    output_base: int,
) -> (
    []int,
    Error,
) {
    // true if any of the digits is negative
    hasNegativeDigit := slice.any_of_proc(digits, proc(digit: int) -> bool {
        return digit < 0
    })

    // Anonymous procs cannot capture variables from outer scope...
    // true if any of the digits is greater than the input base
    hasHighDigit := false
    for digit in digits {
        if (digit >= input_base) {
            hasHighDigit = true
            break
        }
    }

    // The error cases below are based on the test cases in all_your_base_test.odin
    if (isBaseNegative(input_base) && isBaseNegative(output_base)) {
        // Both input and output bases are negative
        return nil, .Input_Base_Too_Small
    } else if (isBaseSmall(input_base)) {
        // Just the input base is too small
        return nil, .Input_Base_Too_Small
    } else if (isBaseSmall(output_base)) {
        // Just the output base is too small
        return nil, .Output_Base_Too_Small
    } else if (hasNegativeDigit || hasHighDigit) {
        // Check if there is a negative digit
        return nil, .Invalid_Input_Digit
    }

    inputBase10 := convertToBase10(input_base, digits)

    // fmt.printfln("input base 10: %d", inputBase10)

    outputDigits := digitsFromBase10(output_base, inputBase10)
    //defer delete(outputDigits)

    //numDigits := len(outputDigits)
    //copy(outputDigitsGlobal[:numDigits], outputDigits[:])

    // numDigits := digitsFromBase10(output_base, inputBase10)

    // Please implement the `rebase` procedure.
    return outputDigits[:], Error.None
}
