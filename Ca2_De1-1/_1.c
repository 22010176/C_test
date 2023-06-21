#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* _1() {
  char x[11];
  int i, a = 0;
  do {
    printf("Nhap xau: ");
    gets(x);
    for (i = 0;i < strlen(x);i++) if (isalpha(x[i])) {
      a = 1;
      break;
    }
    if (!a) break;
  } while (strlen(x) < 10);
  return memcpy(malloc(strlen(x) + 1), x, strlen(x) + 1);
}
char* _2(char* a) {
  char z[strlen(a) + 1];
  int i; for (i = 0; i < strlen(a);i++) z[i] = (char)((int)a[i] - 48 + (i % 2 ? 65 : 97));
  z[i++] = '\0';
  free(a);
  return memcpy(malloc(i), z, i);
}
int main() {
  char* z = _2(_1());
  printf("Xau ma hoa: %s"z);
  free(z);
}