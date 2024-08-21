#include <assert.h>
#include <errno.h>
#include <hay/utils.h>
#include <stdint.h>

int main() {
  char *s = "100";
  uintmax_t r = hay_utils_stou(s);
  assert(errno == 0);
  assert(r == 100);

  return 0;
}
