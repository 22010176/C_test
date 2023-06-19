#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#define FF fflush(stdin)
#define P printf
char* _A() {
  printf("Nhap xau a: ");
  char* a = malloc(100);
  FF; gets(a);
  if (tolower(a[0]) != 'p' || strlen(a) < 6) {
    free(a);
    return _A();
  }
  for (int i = 0, _a = 0, b = 0;i < strlen(a);i++) {
    if (isdigit(a[i])) _a = 1;
    if (isupper(a[i])) b = 1;
    if (_a && b) return a;
  }
  free(a);
  return _A();
}
void _B(char* a) {
  int cha, nu;
  cha = nu = 0;
  for (int i = 0;i < strlen(a);i++) {
    if (isalpha(a[i])) cha++;
    if (isdigit(a[i])) nu++;
  }
  printf("%d %d\n", cha, nu);
}
char* _C(char* a) {
  char* c = malloc((strlen(a) + 1) * sizeof(char));
  int j = 0;
  for (int i = 0; i < strlen(a);i++) {
    char x = a[i];
    if (!isalnum(x)) continue;
    c[j++] = x;
  }
  c[j++] = '\0';
  return realloc(c, j);
}
int main() {
  char* s = _A();
  _B(s);
  P(_C(s));
}