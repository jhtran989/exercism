package two_fer

import "core:fmt"

two_fer :: proc(name: string = "") -> string {
    // Default to "you"
    objectName := "you"

    // Replace with given string if it is not the empty string
    if name != "" {
        objectName = name
    }

    return fmt.aprintf("One for %s, one for me.", objectName)
}
