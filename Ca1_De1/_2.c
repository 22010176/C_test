#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _m malloc
#define _s sizeof
#define pr printf
#define sc fflush(stdin); scanf
#define gs fflush(stdin); gets

typedef struct {
  char hsx[11], id[21];
  int c, r; float p;
} Dat;

char* InSt(char i[], int len) {
  char x[len + 1];
  do { printf(i); gs(x); } while (strlen(x) > len || !strlen(x));
  return memcpy(_m(len + 1), x, len + 1);
}
int InCh() {
  int x;
  do { pr("Nhap chip (i3 - i5 - i7): "); sc("%d", &x); } while (x != 3 && x != 5 && x != 7);
  return x;
}
int InRa() {
  int x;
  do { pr("Nhap chip (i3 - i5 - i7): "); sc("%d", &x); } while (x % 4);
  return x;
}
float InPr() {
  float x;
  do { pr("Nhap gia "); sc("%f", &x); } while (x < 0);
  return x;
}
char* GeID(char* hsx, int c, int r) {
  char* x; do { x = _m(1000); } while (!x);
  sprintf(x, "%s.i%d.%d", hsx, c, r);
  return realloc(x, strlen(x) + 1);
}
Dat* CrDa(char* hsx, int c, int r, float p) {
  Dat* x = _m(_s(Dat));
  strcpy(x->hsx, hsx);
  strcpy(x->id, GeID(hsx, c, r));
  x->r = r; x->p = p;
  return x;
}
Dat* GeDa() {
  char hsx[11]; int c, r;float p;
  itoa(rand(), hsx, 16);
  c = rand(), r = rand(), p = rand();
  return CrDa(hsx, c, r, p);
}
Dat* InDa() {
  char* hsx = InSt(10);
  int c = InCh(), r = InRa();
  float p = InPr();
}
Dat** InNDa() {}
Dat** GeNDA() {}

void Swap() {}
void Sorting() {}

void PrDa() {}
void PrNDa() {}

void _5() {}
int main() {
}