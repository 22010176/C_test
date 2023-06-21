#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
int Ch(char* a) {
  int i; for (i = 0; i < strlen(a);i++) if (!isdigit(a[i]))return 0;
  return 1;
}
char* _1() {
  char a[101];
  do { printf("Nhap a: "); fflush(stdin);  gets(a); } while (strlen(a) > 100 || !Ch(a));
  int i = strlen(a) + 1;
  return memcpy(malloc(i), a, i);

}
void _2(char* x) {
  int* c = calloc(256, sizeof(int)), i, j;
  for (i = 0; i < strlen(x);i++) c[(int)x[i]]++;
  for (i = j = 0; i < 256;i++) if (c[j] < c[i]) j = i;
  printf("%c lap lai %d lan", j, c[j]);
  free(x);
}
int main() {
  _2(_1());
}