#include <assert.h>
#include <errno.h>
#include <hay/utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *s = NULL;
  int n = -100;
  int r = hay_utils_itos(n, s);
  assert(r < 0);
  assert(errno != 0);
  assert(errno == EINVAL);
  assert(s == NULL);

  return 0;
}
