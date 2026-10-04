package custom_set

import "core:fmt"
import "core:slice"
import "core:strings"

// Replace the definition of Set with your own.
// Note: It doesn't have to be a `struct`.
Set :: struct {
    // Implementation used map for common lookups
    // struct{} has 0 bytes for the values (empty type)
    items: map[int]struct{},
}

new_set :: proc(elements: ..int) -> Set {
    set: Set
    add(&set, ..elements)

    return set
}

destroy_set :: proc(s: ^Set) {
    // Do nothing if s is nil
    if s == nil {
        return
    }

    // Items in set are not allocated (int) so just need to destroy the
    // items in the set
    // Otherwise, need to destroy each item first BEFORE destroying the items
    delete(s.items)

    // NOTE: Make sure to NOT free the set (let caller handle free the set)
    //free(s)
}

to_string :: proc(s: Set) -> string {
    // Make sure to delete allocated slices (like with slice.map_keys())
    setItems, err := slice.map_keys(s.items)
    defer delete(setItems)
    assert(err == nil)

    // Make sure to sort the items (based on tests)
    slice.sort(setItems)

    stringsBuilder: strings.Builder
    strings.builder_init(&stringsBuilder)

    // Separator based on tests
    separator := ", "

    strings.write_string(&stringsBuilder, "[")
    for item, i in setItems {
        if i > 0 {
            strings.write_string(&stringsBuilder, separator)
        }

        strings.write_int(&stringsBuilder, item)
    }
    strings.write_string(&stringsBuilder, "]")

    return strings.to_string(stringsBuilder)
}

is_empty :: proc(s: Set) -> bool {
    return len(s.items) == 0
}

contains :: proc(s: Set, element: int) -> bool {
    return element in s.items
}

is_subset :: proc(s: Set, other: Set) -> bool {
    // Look through items of target subset to see if other set does not
    // contain it
    for item in s.items {
        if (!contains(other, item)) {
            return false
        }
    }

    return true
}

is_disjoint :: proc(s: Set, other: Set) -> bool {
    // Similar to is_subset() but return false if the other set has any of the
    // items of the target set
    for item in s.items {
        if (contains(other, item)) {
            return false
        }
    }

    return true
}

equal :: proc(s: Set, other: Set) -> bool {
    // Both the set and other set are subsets of each other (both directions)
    return is_subset(s, other) && is_subset(other, s)
}

add :: proc(s: ^Set, elements: ..int) {
    for element in elements {
        if element not_in s.items {
            s.items[element] = {}
        }
    }

}

intersection :: proc(s: Set, other: Set) -> Set {
    set: Set

    // Similar logic to is_disjoint() but add items to intersection set instead
    // of returning false
    for item in s.items {
        if (contains(other, item)) {
            add(&set, item)
        }
    }

    return set
}

difference :: proc(s: Set, other: Set) -> Set {
    set: Set

    // Similar to intersection() but add when the opposite condition is
    // true (other set does not contain the current item from the set when
    // looping)
    for item in s.items {
        if (!contains(other, item)) {
            add(&set, item)
        }
    }

    return set
}

// union is a reserved word in Odin, using join instead.
join :: proc(s: Set, other: Set) -> Set {
    set: Set

    // Make sure to delete allocated slices (like with slice.map_keys())
    setItems, err := slice.map_keys(s.items)
    defer delete(setItems)
    assert(err == nil)

    otherSetItems, otherErr := slice.map_keys(other.items)
    defer delete(otherSetItems)
    assert(otherErr == nil)

    // Simple approach of adding the items of both the set and the other set
    // to the same return set
    add(&set, ..setItems)
    add(&set, ..otherSetItems)

    return set
}
