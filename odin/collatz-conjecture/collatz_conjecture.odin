package collatz_conjecture

countStepsHelper :: proc(currentResult: int, numSteps: int) -> int {
    // Base case (end of steps)
    if (currentResult == 1) {
        return numSteps
    }

    if (currentResult %% 2 == 0) {
        // Even step
        return countStepsHelper(currentResult / 2, numSteps + 1)
    } else {
        // Odd step
        return countStepsHelper(3 * currentResult + 1, numSteps + 1)
    }
}

countSteps :: proc(result: int) -> int {
    // Call helper with initial steps as 0 (since result of 1 should return 0
    // steps)
    return countStepsHelper(result, 0)
}

// Returns the number of steps to get to a value of 1.
steps :: proc(start: int) -> (result: int, ok: bool) {
    // Return 0 and false if result is non positive
    // result and ok are zero initialized
    if (start <= 0) {
        return
    }

    // The input should be valid at this point
    result = countSteps(start)
    ok = true

    // Still need return statement
    return
}
