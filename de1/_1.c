#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define gs fflush(stdin);gets
#define _p printf
#define _m malloc 
int check(char* s) {
  if (strlen(s) > 6 || toupper(s[0]) != 'P') return 1;
  int i, a, b;
  for (i = a = b = 0; i < strlen(s);i++) {
    char x = s[i];
    if (isupper(x)) a = 1;
    if (isdigit(x)) b = 1;
    if (a && b) return 0;
  }
  return 1;
}
char* _1() {
  char* a = _m(7);
  int i = 0;
  _p("Nhap 1 xau co 6 ki tu, it nhat mot chu hoa, mot chu so.\nBat dau bang 'P' hoac 'p'.");
  _p("Nhap xau: ");
  do {
    if (i++) printf("Ko hop le! Nhap lai: ");
    gs(a);
  } while (check(a));
  return a;
}
void _2(char* s) {
  int i, a, b;
  for (i = a = b = 0; i < strlen(s);i++) {
    if (isdigit(s[i])) a++;
    if (isalpha(s[i])) b++;
  }
  printf("Co %d so va %d chu.\n", a, b);
}

void _3(char* s) {
  int i, j;for (i = j = 0; i < strlen(s);i++) {
    if (!isalnum(s[i])) continue;
    s[j++] = s[i];
  }
  s[j] = '\0';
}
int main() {
  char* a = _1();
  _2(a); _3(a);
  _p(a);
}