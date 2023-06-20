#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define sc fflush(stdin); scanf
#define gs fflush(stdin); gets
#define _m malloc
#define _p printf
#define _s sizeof
typedef struct {
  char h[10], t[15];
  int r, c; float g;
} Data;
// get chip
char* GeCh(int x) {
  switch (x) {
  case 1: return "Exynos";
  case 2: return "SnapDragon";
  case 3: return "M1";
  case 4: return "M2";
  default: return "";
  }
}
// check data
int ChDa(char* h, char* t, int r, int c, float g) {
  if (strrchr(h, ' ') || strrchr(t, ' ')) return 1;
  int _h = strlen(h), _t = strlen(t);
  return !_h || !_t || _h > 10 || !_t > 15 || r < 0 || c < 0 || g < 0 || c > 4 || r % 4;
}
// create data
Data* CrDa(char* h, char* t, int r, int c, float g) {
  if (ChDa(h, t, r, c, g)) return (Data*)-1;
  Data* x; do { x = _m(_s(Data)); } while (!x);
  x->r = r, x->c = c, x->g = g;
  strcpy(x->h, h);
  strcpy(x->t, t);
  return x;
}
// Nhap data
Data* InDa() {
  char h[10], t[15]; int r, c, i = 0; float g;
  do {
    if (i++) _p("Ko hop le!!\n");
    _p("nhap ten hang: "); gs(h);
    _p("Nhap ten may: "); gs(t);
    _p("Nhap ram: "); sc("%d", &r);
    _p("Nhap chip:\n1. Exynos\n2. SnapDragon\n3. M1\n4. M2\nBan chon: ");
    sc("%d", &c); _p("Nhap gia: ");
    sc("%f", &g);
  } while (ChDa(h, t, r, c, g));
  return CrDa(h, t, r, c, g);
}
// create n data
Data** CrNDa(int n) {
  Data** dat;
  do { dat = _m(_s(Data*) * (n + 1)); } while (!dat);
  int i; for (i = 0; i < n;i++) {
    _p("Nhap may thu %d: \n", i + 1);
    dat[i] = InDa();
  }
  dat[n] = (Data*)-1;
  return dat;
}
// print data
void PrDa(Data* x, int* n, int i) {
  char r[100];
  itoa(x->r, r, 10); strcat(r, "GB");
  _p("| %*d | %*s | %*s | %*s | %*s | %*.1f |\n", n[0], i, n[1], x->h, n[2], x->t, n[3], r, n[4], GeCh(x->c), n[5], x->g);
}
char* PrLi(int* n, int l) {
  int i, j, _a = 0, _l = 100; char* a = _m(_l);
  for (i = 0; i < l;i++) {
    int b = abs(n[i]) + 2;
    a[_a++] = '+';
    for (j = 0; j < b;j++) a[_a++] = '-';
    if (strlen(a) + abs(n[i + 1]) < _l) continue;
    _l *= 2;
    a = realloc(a, _l);
  }
  a[_a++] = '+'; a[_a++] = '\0';
  return realloc(a, _a);
};
// print n data
void PrNDa(Data** x, int n) {
  int _x[] = { 3,-15,-15,6,-19,15 };
  char* li = PrLi(_x, 6);
  _p("%s\n", li);
  _p("| %*s | %*s | %*s | %*s | %*s | %*s |\n", _x[0], "STT", _x[1], "Ten hang", _x[2], "Ten may", _x[3], "RAM", _x[4], "Chip", _x[5], "Gia");
  _p("%s\n", li);
  int i; for (i = 0; i < n && x[i] != (Data*)-1;i++) {
    PrDa(x[i], _x, i + 1);
    _p("%s\n", li);
  }
  _p("\n");
}
// Sorting
void Swap(Data** a, Data** b) { Data* t = *a; *a = *b, * b = t; }
void Sorting(Data** x, int l) {
  int i, j; for (i = 0; i < l;i++) for (j = 0; j < l - i - 1;j++)
    if (strcmp(x[j]->t, x[j + 1]->t) < 0) Swap(x + j, x + j + 1);
}
Data** Filtering(Data** x, int l, int a, float b, float c) {
  Data** re = _m(l * _s(Data*));
  int i, j; for (i = j = 0; i < l;i++) {
    Data* _b = x[i];
    if (x[i]->r >= a && b <= x[i]->g && x[i]->g <= c) re[j++] = _b;
  }
  re[j++] = (Data*)-1;
  return realloc(re, j * _s(Data*));
}
// final
void _5() {
  int n, r;float a, b;
  _p("Nhap so san pham: ");
  sc("%d", &n);
  Data** dat = CrNDa(n);
  _p("Bang san pham: \n");
  PrNDa(dat, n);

  Sorting(dat, n);
  _p("Sau khi sap xep theo ten: \n");
  PrNDa(dat, n);

  _p("Nhap ram can tim: ");
  sc("%d", &r);
  _p("Nhap khoang gia: ");
  sc("%f%f", &a, &b);
  Data** f = Filtering(dat, n, r, a, b);
  _p("Bang san pham thoa man: \n");
  PrNDa(f, n);
}
int main() { _5(); }
