#include <assert.h>
#include <errno.h>
#include <hay/utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *s = malloc(1024 * sizeof(char));
  int n = -100;
  int r = hay_utils_itos(n, s);
  assert(r >= 0);
  assert(errno == 0);
  assert(s != NULL);
  assert(strcmp(s, "-100") == 0);

  return 0;
}
