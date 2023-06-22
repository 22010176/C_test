#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ff fflush(stdin)
int _1(char* a) {
  if (strlen(a) > 10) return 0;
  int _a, i, x;
  for (_a = 0, i = 0, x = 0;i < strlen(a);i++) {
    if (isalnum(a[i])) _a = 1;
    if (strchr("!@#$%^&*()", a[i])) x = 1;
    if (_a && x) return 1;
  }
  return 0;
}
void _2(char* _a) {
  for (int i = 0; i < strlen(_a);i++) {
    if (isupper(_a[i])) _a[i] = tolower(_a[i]);
    else if (islower(_a[i])) _a[i] = toupper(_a[i]);
  }
}

int main() {
  char x[100];
  int i = 0;
  do {
    if (i++) printf("Xau ko hop le. ");
    printf("Nhap xau: ");
    ff; gets(x);
  } while (!_1(x));
  _2(x);
  printf(x);
}