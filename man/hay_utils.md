hay_utils.h(3) -- utility functions for Hay projects
====================================================

## SYNOPSIS
`uintmax_t hay_utils_stou(char *s);`  
`intmax_t hay_utils_stoi(char *s);`  
`int hay_utils_itos(int n, char *s);`  

## DESCRIPTION
`hay_utils` is an utility library used by and for various projects of the **Hay Suite**.  
A **Hay Suite** project.

### hay_utils_stou
Converts a string to an unsigned integer.

### hay_utils_stoi
Converts a string to a signed integer.

### hay_utils_itos
Converts an integer to a string.

## PARAMETERS
### hay_utils_stou
* **`s`**: 
  A pointer to a string containing the representation of an unsigned integer. The string should consist of digits and optionally include leading whitespace. If the string is `NULL`, the function sets `errno` to `EINVAL` and returns `0`.

### hay_utils_stoi
* **`s`**: 
  A pointer to a string containing the representation of a signed integer. The string can include leading whitespace, an optional sign (`+` or `-`), and digits. If the string is `NULL`, the function sets `errno` to `EINVAL` and returns `0`.

### hay_utils_itos
* **`n`**: 
  The integer to convert to a string.
* **`s`**: 
  A pointer to a buffer where the resulting string will be stored. The buffer should be large enough to hold the string representation of the integer. If the buffer is `NULL`, the function sets `errno` to `EINVAL` and returns `-1`.

## RETURN VALUE
### hay_utils_stou
Returns the converted unsigned integer. If the input string is invalid or `NULL`, the function sets `errno` to `EINVAL` and returns `0`.

### hay_utils_stoi
Returns the converted signed integer. If the input string is invalid or `NULL`, the function sets `errno` to `EINVAL` and returns `0`.

### hay_utils_itos
Returns the length of the resulting string. If the buffer is `NULL` or too small to hold the integer, the function sets `errno` to `EINVAL` and returns `-1`.

## ERRORS
* **`EINVAL`**: 
  This error code is set if the input string is `NULL`, contains invalid characters, or if the buffer is `NULL` in the `hay_utils_itos` function. It indicates that an invalid argument was provided.

* **`ENOMEM`**: 
  Not applicable to these functions as they do not perform dynamic memory allocation. 

## FUNCTIONS
### hay_utils_stou()

```c
uintmax_t hay_utils_stou(char *s);
```
Converts the string `s` to an unsigned integer. Handles non-digit characters by setting `errno` to `EINVAL` if encountered.

### hay_utils_stoi()

```c
intmax_t hay_utils_stoi(char *s);
```
Converts the string `s` to a signed integer. Handles optional sign characters and non-digit characters by setting `errno` to `EINVAL` if invalid input is detected.

### hay_utils_itos()

```c
int hay_utils_itos(int n, char *s);
```
Converts the integer `n` to a string and stores it in the buffer pointed to by `s`. Returns the length of the string. If `s` is `NULL`, sets `errno` to `EINVAL` and returns `-1`.

## EXAMPLES
The following examples demonstrate how to use the `hay_utils_stou`, `hay_utils_stoi`, and `hay_utils_itos` functions:

### Example 1: Using hay_utils_stou and hay_utils_stoi

```c
#include <hay/utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char num_str[] = "12345";
    uintmax_t u_val = hay_utils_stou(num_str);
    intmax_t s_val = hay_utils_stoi(num_str);

    if (errno) {
        perror("Conversion error");
        return EXIT_FAILURE;
    }

    printf("Unsigned value: %ju\n", u_val);
    printf("Signed value: %jd\n", s_val);

    return EXIT_SUCCESS;
}
```

### Example 2: Using hay_utils_itos

```c
#include <hay/utils.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 12345;
    char buffer[20]; // Sufficiently large buffer
    int length = hay_utils_itos(num, buffer);

    if (length == -1) {
        perror("Conversion error");
        return EXIT_FAILURE;
    }

    printf("String representation: %s\n", buffer);

    return EXIT_SUCCESS;
}
```

In these examples:
1. `hay_utils_stou` and `hay_utils_stoi` convert string representations of numbers to `uintmax_t` and `intmax_t` respectively.
2. `hay_utils_itos` converts an integer to its string representation and stores it in the provided buffer.

## SEE ALSO
errno(3), strerror(3), sprintf(3)

## AUTHOR
Written by Hay Foundation. Contributions and feedback can be directed to <nobody@rajdeepm.xyz>.

## COPYRIGHT
This manpage is released under the **Mozilla Public License, version 2.0** License.
