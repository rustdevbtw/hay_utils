#include <errno.h>
#include <hay/utils.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Convert a string to an unsigned integer.
 *
 * This function converts a null-terminated string to an unsigned integer
 * (`uintmax_t`). It processes each character in the string, ensuring it
 * represents a valid digit (0-9), and calculates the integer value accordingly.
 * If an invalid character is found or the input string is NULL, `errno` is set
 * to `EINVAL` and the function returns 0.
 *
 * @param s The string to be converted. It should be a null-terminated string
 * consisting only of digit characters (0-9).
 * @return The converted unsigned integer value. If an error occurs, returns 0
 * and sets `errno` to `EINVAL`.
 */
uintmax_t hay_utils_stou(char *s) {
  if (s == NULL) {
    errno = EINVAL; // Set errno to EINVAL if the input string is NULL
    return 0;
  }

  int len = strlen(s); // Determine the length of the input string
  uintmax_t r = 0;     // Initialize the result variable

  for (int i = 0; i < len; i++) {
    int p = (len - i) -
            1; // Calculate the positional power of 10 for the current digit
    int j = s[i] - '0';   // Convert the current character to its numeric value
    if (j < 0 || j > 9) { // Check if the character is not a valid digit
      errno = EINVAL;     // Set errno to EINVAL for invalid character
      return 0;
    }
    r += j * pow(10, p); // Add the digit's value to the result
  }

  errno = 0; // Clear errno on successful conversion
  return r;
}

/**
 * @brief Convert a string to a signed integer.
 *
 * This function converts a null-terminated string to a signed integer
 * (`intmax_t`). It processes each character in the string, handling optional
 * leading '+' or '-' signs and calculating the integer value. If an invalid
 * character is found or the input string is NULL, `errno` is set to `EINVAL`
 * and the function returns 0.
 *
 * @param s The string to be converted. It should be a null-terminated string
 * consisting of optional sign characters ('+' or '-') followed by digit
 * characters (0-9).
 * @return The converted signed integer value. If an error occurs, returns 0 and
 * sets `errno` to `EINVAL`.
 */
intmax_t hay_utils_stoi(char *s) {
  if (s == NULL) {
    errno = EINVAL; // Set errno to EINVAL if the input string is NULL
    return 0;
  }

  int len = strlen(s); // Determine the length of the input string
  uintmax_t r = 0;     // Initialize the result variable
  int sign = 0; // Initialize the sign variable (0 for positive, 1 for positive,
                // -1 for negative)

  for (int i = 0; i < len; i++) {
    if (s[i] == '+' && i == 0) { // Handle leading '+' sign
      sign += 1;
      continue;
    }
    if (s[i] == '-' && i == 0) { // Handle leading '-' sign
      sign -= 1;
      continue;
    }

    int p = (len - i) -
            1; // Calculate the positional power of 10 for the current digit
    int j = s[i] - '0';   // Convert the current character to its numeric value
    if (j < 0 || j > 9) { // Check if the character is not a valid digit
      errno = EINVAL;     // Set errno to EINVAL for invalid character
      return 0;
    }
    r += j * pow(10, p); // Add the digit's value to the result
  }

  errno = 0; // Clear errno on successful conversion
  switch (sign) {
  case 0:
    return r; // No sign, return the result as is
  case 1:
    return r * +1; // Positive sign, return the result as is
  case -1:
    return r * -1; // Negative sign, return the negated result
  default:
    return r; // Default case, should not occur, return the result as is
  }
}

/**
 * @brief Convert an integer to a string.
 *
 * This function converts an integer to its string representation and stores it
 * in the provided buffer. The buffer should be large enough to hold the string
 * representation of the integer, including the null terminator.
 *
 * @param n The integer to be converted to a string.
 * @param s The buffer where the resulting string will be stored. It should be a
 * writable buffer with sufficient size.
 * @return 0 on success, or -1 if an error occurs. If the buffer `s` is NULL,
 * sets `errno` to `EINVAL`.
 */
int hay_utils_itos(int n, char *s) {
  if (s == NULL) {
    errno = EINVAL; // Set errno to EINVAL if the destination buffer is NULL
    return -1;
  }

  // Determine if the number is negative
  int is_negative = 0;
  if (n < 0) {
    is_negative = 1;
    n = -n; // Make n positive for easier processing
  }

  // Calculate the number of digits needed
  int num_digits = 1; // At least one digit is needed
  int temp = n;
  while (temp >= 10) {
    temp /= 10;
    num_digits++;
  }

  // Account for the negative sign
  if (is_negative) {
    num_digits++;
  }

  // Account for the null terminator
  num_digits++;

  // Check if the buffer is large enough
  if (num_digits > INT_MAX) {
    errno = EINVAL; // Buffer size check failed
    return -1;
  }

  // Set the end of the string buffer
  s[num_digits - 1] = '\0';

  // Convert integer to string in reverse
  int index = num_digits - 2;
  while (n > 0) {
    s[index--] = (n % 10) + '0';
    n /= 10;
  }

  // Add negative sign if necessary
  if (is_negative) {
    s[index--] = '-';
  }

  return 0; // Return 0 on success
}
