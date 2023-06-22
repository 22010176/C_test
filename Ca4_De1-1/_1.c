#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int check(char* x) {
  if (strlen(x) < 6 || !isupper(x[0])) return 0;
  int i, n;
  for (i = n = 0;i < strlen(x);i++) if (isdigit(x[i])) n++;
  return n >= 2;
}
char* _1() {
  char x[1000];
  do {
    printf("Nhap xau: ");
    fflush(stdin); gets(x);
  } while (!check(x));
  int z = strlen(x) + 1;
  return memcpy(malloc(z), x, z);
}
int _2(char* x) {
  int l = strlen(x), i;
  for (i = 0; i < l;i++) if (x[i] != x[l - 1 - i]) return 0;
  return 1;
}
void _3(char* x) {
  int i; for (i = 0;i < strlen(x);i++) {
    if (isupper(x[i])) x[i] = tolower(x[i]);
    else if (islower(x[i]))x[i] = toupper(x[i]);
  }
}
void _4() {
  char* a = _1();
  if (_2(a)) printf("string %s thoa man tinh doi xung.", a);
  _3(a);
  printf("string ket qua sau khi chuyen doi : %s", a);
}
int main() { _4(); }