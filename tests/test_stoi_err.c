#include <assert.h>
#include <errno.h>
#include <hay/utils.h>
#include <stdint.h>

int main() {
  char *s = "+abcd";
  intmax_t r = hay_utils_stoi(s);
  assert(errno != 0);
  assert(errno == EINVAL);
  assert(r == 0);

  return 0;
}
