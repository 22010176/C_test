#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define P printf
#define ff fflush(stdin)
#define sc scanf
#define gs gets
#define _m malloc
#define _s sizeof

typedef struct {
  char h[100], n[100], c[100];
  int r; float p;
} Data;
int ChDa(char* h, char* n, char* c, int  r, float p) {
  int _h = strlen(h), _n = strlen(c), _c = strlen(c);
  return !(_h && _n && _c) || _h > 10 || _n > 15 || r <= 0 || p <= 0 || r % 4 != 0;

}
int GetL(void** A) {
  int i; for (i = 0; A[i] != (void*)-1;i++);
  return i;
}

char* GetC(int x) {
  switch (x) {
  case 1: return "Exynos";
  case 2: return "SnapDragon";
  case 3: return "M1";
  case 4: return "M2";
  default: return "";
  }
}
Data* CrDa(char* h, char* n, char* c, int r, float p) {
  if (ChDa(h, n, c, r, p)) return (Data*)-1;
  Data* x = _m(_s(Data));
  strcpy(x->h, h);
  strcpy(x->n, n);
  strcpy(x->c, c);
  x->r = r;
  x->p = p;
  return x;
}
Data* GeDa() {
  char h[100], n[100];
  int r, c; float p;
  do {
    p = (float)(rand() % 10000000 + 1000) / 100;
    c = rand() % 4 + 1, r = (rand() % 90) * 4;
    itoa(rand(), h, 16);
    itoa(rand(), n, 16);
  } while (ChDa(h, n, GetC(c), r, p));
  return CrDa(h, n, GetC(c), r, p);
}
void PrDa(Data* d) {
  printf("| %*s | %*s | %*s | %*d | %*.2f |\n", 20, d->h, 20, d->n, 15, d->c, 10, d->r, 10, d->p);
}
void PrNDa(Data** d) {
  int i; for (i = 0; d[i] != (void*)-1; i++) {
    printf("| %*d", 5, i + 1);
    PrDa(d[i]);
  }
}
Data* InDa() {
  char h[100], t[100];
  int j = 0, r, c; float p;
  do {
    if (j++) printf("Ko hop le!!!\n");
    printf("Nhap hang: ");
    ff; gs(h);
    printf("Nhap ten: ");
    ff; gs(t);
    printf("Nhap chip (1-4): ");
    ff; sc("%d", &c);
    printf("Nhap ram (chia het cho 4): ");
    ff; sc("%d", &r);
    printf("Nhap gia (>0): ");
    ff; sc("%f", &p);
  } while (ChDa(h, t, GetC(c), r, p));
  return CrDa(h, t, GetC(c), r, p);
}
void** InNDa(int n) {
  void** dat = _m((n + 1) * sizeof(void*));
  int i; for (i = 0; i < n;i++) {
    printf("\nNhap may thu %d:\n", i + 1);
    dat[i] = InDa();
  }
  dat[n] = (Data*)-1;
  return dat;
}
void** CrNDa(int n) {
  void** dat = _m((n + 1) * sizeof(void*));
  int i;for (i = 0;i < n;i++) dat[i] = GeDa();
  dat[i] = (void*)-1;
  return dat;
}
void Swap(void** a, void** b) {
  void* t = *a;
  *a = *b; *b = t;
}
void** CpyA(void** A, int s) {
  int l = GetL(A), i;
  void** x = _m((l + 1) * _s(void*));
  for (i = 0; A[i] != (void*)-1; i++) {
    x[i] = _m(s);
    memcpy(x[i], A[i], s);
  }
  x[i] = (void*)(-1);
  return x;
}
void** Sorting(void** A, int s, int (*_f)(void*, void*)) {
  void** B = CpyA(A, s); int i, j, l = GetL(A);
  for (i = 0; i < l;i++) for (j = 0; j < l - 1 - i;j++)
    if (_f(B[j], B[j + 1])) Swap(B + j, B + j + 1);
  return B;
}
void** Filter(void** A, int s, int (*f)(void*, int, float, float), int a, float b, float c) {
  int i, j, l = GetL(A); void** B = _m(s * (l + 1));
  for (i = j = 0; i < l;i++) if (f(A[i], a, b, c)) B[j++] = A[i];
  B[j++] = (void*)-1;
  return realloc(B, j * s);
}
int _S(void* a, void* b) {
  Data* _a = (Data*)a, * _b = (Data*)b;
  return _a->p > _b->p;
}
int _S2(void* _a, int a, float b, float c) {
  Data* _b = (Data*)_a;
  return a <= _b->r && b <= _b->p && _b->p <= c;
}
int main() {
  srand(time(NULL));

  Data** _1 = (Data**)CrNDa(1000);
  Data** _3 = (Data**)Sorting((void**)_1, _s(Data), _S);
  Data** _4 = (Data**)Filter((void**)_1, _s(Data), _S2, 300, 0, 50);

  PrNDa(_1);
  PrNDa(_3);
  PrNDa(_4);

}