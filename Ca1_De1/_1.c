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
  char* z = strdup(a);
  char* t = strstr(z, b);
  int i;
  while (t) {
    for (i = 0; i < strlen(b);i++) t[i] = '-';
    t = strstr(z, b);
  }
  int l = strlen(z) + 1;
  return memcpy(malloc(l), z, l);
}
char* _2(char* a, char b) {
  int l = strlen(a) + 1, i, j; char c[l];
  for (i = j = 0; i <= strlen(a);i++) if (a[i] != b) c[j++] = a[i];
  return memcpy(malloc(l), c, l);
}
char* _3() {
  char a[1000], b[1000]; int i;
  do {
    if (i++) printf("Xau a phai dai hon xau b.\n\n");
    printf("Nhap xau thu nhat: "); fflush(stdin); gets(a);
    printf("Nhap xau thu hai: "); fflush(stdin); gets(b);
  } while (strlen(b) > strlen(a));
  strcpy(a, _1(a, b));
  printf("Ket qua cau 1: %s\n", a);
  printf("Ket qua cau 2: %s\n", _2(a, '-'));
}
int main() {
  _3();
}