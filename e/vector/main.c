#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void* data;
  int (*geti)();
  char(*getc)();
  float(*getf)();
} Node;

typedef struct {
  void** this;
  int len;

} Vector;
void PrTable(void** x, char** ti, char (*format_Data)(void*)) {}
int main() {
  char a[][9] = { "12344\n","456","789" };
  int x[][4] = { {1,2,3},{3,4,5},{3,4,5} };
  for (int i = 0; i < 3;i++) {
    printf(a[i]);
  }
}