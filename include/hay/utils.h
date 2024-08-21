#ifndef HAY_UTILS_H
#define HAY_UTILS_H
#include <stdint.h>

/**
 * @brief Convert a string to an unsigned integer.
 *
 * This function converts a null-terminated string to an unsigned integer
 * (`uintmax_t`). The string must represent a valid non-negative integer. If the
 * string is invalid (i.e., contains non-digit characters or is NULL), the
 * function sets `errno` to `EINVAL` and returns 0.
 *
 * @param s The string to be converted. It should be a null-terminated string
 * consisting only of digit characters (0-9).
 * @return The converted unsigned integer value. If an error occurs, returns 0
 * and sets `errno` to `EINVAL`.
 *
 * @note The function assumes that the input string is a valid representation of
 * an unsigned integer and does not handle cases of integer overflow.
 */
uintmax_t hay_utils_stou(char *s);

/**
 * @brief Convert a string to a signed integer.
 *
 * This function converts a null-terminated string to a signed integer
 * (`intmax_t`). The string must represent a valid integer, with optional
 * leading '+' or '-' sign. If the string is invalid (i.e., contains non-digit
 * characters or is NULL), the function sets `errno` to `EINVAL` and returns 0.
 *
 * @param s The string to be converted. It should be a null-terminated string
 * consisting of optional sign characters ('+' or '-') followed by digit
 * characters (0-9).
 * @return The converted signed integer value. If an error occurs, returns 0 and
 * sets `errno` to `EINVAL`.
 *
 * @note The function does not handle integer overflow and assumes that the
 * input string represents a valid signed integer.
 */
intmax_t hay_utils_stoi(char *s);

int hay_utils_itos(int n, char *s);
#endif
