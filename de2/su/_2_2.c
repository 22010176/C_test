#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>

#define FF fflush(stdin);
#define pr printf
#define sc scanf

typedef struct {
  float gia; int num;
  char ten[100], size[100];
} Data;

void nhapTen(int len, char* _a) {
  do { FF; gets(_a); } while (!strlen(_a) || strlen(_a) > len);
}
char* getSize(int x) {
  switch (x) {
  case 1: return "S";
  case 2: return "M";
  case 3: return "L";
  case 4: return "XL";
  case 5: return "2XL";
  default: return "";
  }
}
int SizeToNum(char* x) {
  if (!!strcmp(x, "S")) return 1;
  if (!!strcmp(x, "M")) return 2;
  if (!!strcmp(x, "L")) return 3;
  if (!!strcmp(x, "XL")) return 4;
  if (!!strcmp(x, "2XL")) return 5;
  return -1;
}
int IsValid(char* _t, int _s, int _n, float _p) {
  return (strlen(_t) <= 10 && strlen(_t) > 0) && (0 < _s && _s < 6) && (_n >= 0 && _p > 0);
}
Data* NhapSanPham(char* _t, int _s, int _n, float _p) {
  if (!IsValid(_t, _s, _n, _p)) return 0;
  Data* dat = malloc(sizeof(Data));
  dat->num = _n; dat->gia = _p;
  strcpy(dat->ten, _t);
  strcpy(dat->size, getSize(_s));
  return dat;
}
void** LocSP(void** _a, int _l, int(*_f)(void*)) {
  void** a = malloc(_l * sizeof(void*));
  int i, j;for (i = 0, j = 0; i < _l;i++) if (_f(_a[i])) a[j++] = _a[i];
  a[j++] = (void*)-1;
  a = realloc(a, j * sizeof(void*));
  return a;
}
Data** NhapNSanPham(int _n) {
  if (_n <= 0) return 0;
  Data** dat = malloc(sizeof(Data*) * _n);
  char t[100]; int s = 0, n = 0, i;
  float p = 0;
  for (i = 0; i < _n;i++) {
    printf("Nhap san pham %d", i + 1);
    do {
      pr("\nNhap ten: "); FF; gets(t);
      pr("Nhap size/soluong/gia: ");
      FF; sc("%d%d%f", &s, &n, &p);
      dat[i] = NhapSanPham(t, s, n, p);
    } while (!dat[i]);
  }
  return dat;
}
void InSP(Data** A, int _n) {
  int i; for (i = 0; i < _n;i++) {
    if (A[i] == -1) break;
    pr("%d. Ten: %s\t", i + 1, A[i]->ten);
    pr("So Luong: %d\t", A[i]->num);
    pr("gia: %.2lf\t", A[i]->gia);
    pr("Size: %s\t", A[i]->size);
    pr("\n");
  }
  pr("\n");
}
void Swap(void** _a, void** _b) {
  void* temp = *_a;
  *_a = *_b; *_b = temp;
}
void Sorting(void** _a, int _l, int (*_f)(void*, void*)) {
  int i, j;for (i = 0; i < _l;i++) for (j = 0; j < _l - i - 1;j++)
    if (_f(_a[j], _a[j + 1])) Swap(_a + j, _a + j + 1);
}
int S(void* _a, void* _b) {
  Data* a = (Data*)_a, * b = (Data*)_b;
  return a->num > b->num;
}
int S2(void* _a) {
  Data* a = (Data*)_a;
  return a->gia > 33;
}
void _C1(Data** A, int _l) { Sorting(A, _l, S); }
float _C2(Data** A, int _l) {
  float a = 0;
  for (int i = 0; i < _l;i++) a += A[i]->gia * A[i]->num;
  return a;
}
float _D(Data** A, int _l) {
}
void Test() {
  int _n = 6;
  Data** A = malloc(_n * sizeof(Data));
  A[0] = NhapSanPham("Sanpa1", 4, 45, 34.35);
  A[1] = NhapSanPham("Sanpa2", 2, 55, 33.35);
  A[2] = NhapSanPham("Sanpa3", 1, 13, 333.35);
  A[3] = NhapSanPham("Sanpa4", 3, 93, 3.5);
  A[4] = NhapSanPham("Sanpa3", 2, 13, 15);
  A[5] = NhapSanPham("Sanpa3", 5, 13, 233.35);
  InSP(A, _n);
  InSP((Data**)LocSP((void**)A, _n, S2), _n);
  Sorting((void**)A, _n, S);
  InSP(A, _n);
}
int main() {
  Test();
}