#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

// strchr, strrchr, strstr
// strcmp, strncmp, strncmp
// strset, strnset
// strcat, strncat
// atoi, itoa
char* _1(char* a, char* b) {
  char c[strlen(a) + 1]; c[0] = '\0';
  while (1) {
    char* x = strstr(a, b);
    if (!x) break;
    strncat(c, a, x - a);
  }
  return memcpy(malloc(strlen(c) + 1), c, strlen(c) + 1);
}

int main() {
  char a[] = "adbfadf124fadd";
  char b[] = "fad";
  char z[strlen(b) + 1];
  z[strlen(b)] = '\0';
  strset(z, '-');
  char x[strlen(a) + 1], * d;
  int l;
  for (l = 0, *d = strstr(a, b);!d;l += d - a + strlen(d)) {

  }

  printf(x);
}