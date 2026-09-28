# NOTE

Used Odin command below to debug infinite loop (test would not finish) on
specific test.

```sh
odin build . -build-mode:test -debug -out:test.exe -define:ODIN_TEST_THREADS=1
-define:ODIN_TEST_NAMES=armstrong_numbers.test_the_largest_128_bit_number_is_not_an_armstrong_number
```
