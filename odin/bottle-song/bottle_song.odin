package bottle_song

import "core:slice"
import "core:strings"

// Do NOT free this since this is static data (not heap allocated)
TEN_GREEN_BOTTLES_LYRICS := [][]string {
    {
        "One green bottle hanging on the wall,",
        "One green bottle hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be no green bottles hanging on the wall.",
    },
    {
        "Two green bottles hanging on the wall,",
        "Two green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be one green bottle hanging on the wall.",
    },
    {
        "Three green bottles hanging on the wall,",
        "Three green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be two green bottles hanging on the wall.",
    },
    {
        "Four green bottles hanging on the wall,",
        "Four green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be three green bottles hanging on the wall.",
    },
    {
        "Five green bottles hanging on the wall,",
        "Five green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be four green bottles hanging on the wall.",
    },
    {
        "Six green bottles hanging on the wall,",
        "Six green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be five green bottles hanging on the wall.",
    },
    {
        "Seven green bottles hanging on the wall,",
        "Seven green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be six green bottles hanging on the wall.",
    },
    {
        "Eight green bottles hanging on the wall,",
        "Eight green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be seven green bottles hanging on the wall.",
    },
    {
        "Nine green bottles hanging on the wall,",
        "Nine green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be eight green bottles hanging on the wall.",
    },
    {
        "Ten green bottles hanging on the wall,",
        "Ten green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be nine green bottles hanging on the wall.",
    },
}

recite :: proc(start_bottles, take_down: int) -> []string {
    // Any return must be heap allocated since tests will try to free returned
    // string array (should be dynamic)
    // Also, each string must also be heap allocated (instead on the stack)
    // so each string also has to be copied
    if (take_down == 1) {
        // NOTE: Need dynamic array and need to copy each string
        // Need to clone (allocate new slice) for delete in tests
        // singleLyric := slice.to_dynamic(
        //     TEN_GREEN_BOTTLES_LYRICS[start_bottles - 1],
        // )

        currentLyric := TEN_GREEN_BOTTLES_LYRICS[start_bottles - 1]
        singleLyric := make([dynamic]string, 0, len(currentLyric))

        for currentLyricString in currentLyric {
            append(&singleLyric, strings.clone(currentLyricString))
        }

        return singleLyric[:]
    } else {
        // Still need to delete slice copies (since it is not returned)
        requestLyrics := make([][]string, take_down)
        defer delete(requestLyrics)

        numLines := 0
        for i in 0 ..< take_down {
            requestLyrics[i] = TEN_GREEN_BOTTLES_LYRICS[start_bottles - i - 1]
            numLines += len(requestLyrics[i])
        }
        numLines += take_down - 1

        combinedLyrics := make([dynamic]string, 0, numLines)

        // NOTE: Original approach of copying slices won't work because each
        // string also needs to be copied
        // startIndex := 0
        // endIndex := 0
        for requestLyric, i in requestLyrics {
            // startIndex = endIndex + (i > 0 ? 1 : 0)
            // endIndex = startIndex + len(requestLyrics[i])

            // Need to clone EACH string
            // Cannot clone the slice...
            for requestLyricString in requestLyric {

                // requestLyricCopy := slice.clone(requestLyric[:])

                append(&combinedLyrics, strings.clone(requestLyricString))
            }

            if (i < take_down - 1) {
                append(&combinedLyrics, "")
            }
            // copy(combinedLyrics[startIndex:endIndex], requestLyricCopy)
        }

        return combinedLyrics[:]
    }
}
