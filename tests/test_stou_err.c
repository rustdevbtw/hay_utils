#include <assert.h>
#include <errno.h>
#include <hay/utils.h>
#include <stdint.h>

int main() {
  char *s = "abcd";
  uintmax_t r = hay_utils_stou(s);
  assert(errno != 0);
  assert(errno == EINVAL);

  return 0;
}
