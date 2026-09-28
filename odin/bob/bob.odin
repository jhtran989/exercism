#+feature dynamic-literals

package bob

import "core:strings"
import "core:unicode"

Reply :: enum {
    Question,
    Yell,
    QuestionYell,
    Silence,
    Other,
}

REPLY_STRING_MAP := map[Reply]string {
    .Question     = "Sure.",
    .Yell         = "Whoa, chill out!",
    .QuestionYell = "Calm down, I know what I'm doing!",
    .Silence      = "Fine. Be that way!",
    .Other        = "Whatever.",
}

/*
Generated using Claude AI

Numbers and simple puncuation should pass unicode.is_lower() as true
Checks unicode value (includes most common punctuation in ASCII table)
*/
isAllUpper :: proc(s: string) -> bool {
    for r in s {
        if unicode.is_lower(r) {
            return false
        }
    }
    return true
}

/*
Generated using Claude AI
*/
hasNoLetters :: proc(s: string) -> bool {
    for r in s {
        if unicode.is_letter(r) {
            return false
        }
    }
    return true
}

response :: proc(input: string) -> string {
    inputTrimmed := strings.trim_space(input)

    // Handle early return of silence first
    // Avoid indexing if input is completely trimmed (emtpy string)
    isSilence := inputTrimmed == ""
    if (isSilence) {
        return REPLY_STRING_MAP[.Silence]
    }

    isQuestion := inputTrimmed[len(inputTrimmed) - 1] == '?'
    isYell := isAllUpper(inputTrimmed)
    hasNoLettersInput := hasNoLetters(inputTrimmed)

    // Need to process inputs with no letters differently
    // Referenced test cases for the conditions
    if (isQuestion && isYell && !hasNoLettersInput) {
        return REPLY_STRING_MAP[.QuestionYell]
    } else if (isYell && !hasNoLettersInput) {
        return REPLY_STRING_MAP[.Yell]
    } else if (isQuestion) {
        return REPLY_STRING_MAP[.Question]
    }

    return REPLY_STRING_MAP[.Other]
}
