#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
char* NhapStr(int len) {
  printf("Nhap string: ");
  char* a = malloc(len * sizeof(char));
  gets(a); fflush(stdin);
  return a;
}
int CheckStr(char* _a) {
  if (strlen(_a) < 6) return 0;
  if (tolower(_a[0]) != 'p') return 0;

  int hoa, so, i;
  for (i = hoa = so = 0; i < strlen(_a);i++) {
    if (isupper(_a[i])) hoa = 1;
    if (isdigit(_a[i])) so = 1;
  }
  if (hoa && so) return 1;
  return 0;
}
int CountAlpha(char* _a) {
  int i, c;
  for (i = 0, c = 0;i < strlen(_a);i++) c += !!isalpha(_a[i]);
  return c;
}
int CountDitgit(char* _A) {
  int i, c;
  for (i = 0, c = 0;i < strlen(_A);i++) c += isdigit(_A[i]);
  return c;
}

char* _1() {
  do {
    char* a = NhapStr(100000);
    if (CheckStr(a)) return a;
    free(a);
  } while (1);
}
void _2(char* b) {
  printf("Chu cai: %d\n", CountAlpha(b));
  printf("Chu so: %d\n", CountDitgit(b));
}
char* _3(char* A) {
  char* b = malloc(strlen(A) * sizeof(char));
  int i, c;
  for (i = 0, c = 0; i < strlen(A);i++) {
    char x = A[i];
    if (!isalpha(x) && !isdigit(x)) {
      c++;
      continue;
    }
    b[i - c] = A[i];
  }
  b[i - c] = '\0';
  return b;
}
int main() {
  char* a = _1();
  _2(a);
  printf(_3(a));
}
