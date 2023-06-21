#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define _m malloc
#define _s sizeof
#define sc fflush(stdin);scanf
#define gs fflush(stdin);gets
#define le strlen

typedef struct {
  char n[101];
  int by; float h, w, bmi;
} Data;

float CalcBMI(float h, float w) { return w / powf(h, 2); }
int ChDa(char* n, int by, float h, float w) {
  int _n = le(n);
  return _n && _n <= 100 && w && h && 1900 < by && by < 2022;
}
Data* CrDa(char* n, int by, float h, float w) {
  if (!ChDa(n, by, h, w)) return (Data*)-2;
  Data* dat = _m(_s(Data));
  strcpy(dat->n, n);
  dat->by = by; dat->h = h; dat->w = w;
  dat->bmi = CalcBMI(dat->h, dat->w);
  return dat;
}
Data* GeDa() {
  char n[101]; int by; float h, w;
  do {
    itoa(rand(), n, 16);
    by = rand() % 50 + 1990, h = (float)(rand() % 250) / 100, w = rand() % 150;
  } while (!ChDa(n, by, h, w));
  return CrDa(n, by, h, w);
}
Data* NhDa() {
  char n[101]; int by, i = 0; float h, w;
  do {
    if (i++)printf("\nKo hop le! Nhap lai.\n");
    printf("Nhap ten: "); gs(n);
    printf("Nhap nam sinh (1900-2022): "); sc("%d", &by);
    printf("Nhap can nang: "); sc("%f", &w);
    printf("Nhap chieu cao: "); sc("%f", &h);
  } while (!ChDa(n, by, h, w));
  return CrDa(n, by, h, w);
}
Data** NhNDa(int n) {
  Data** x = _m(_s(Data*) * n);
  int i; for (i = 0; i < n;i++) {
    printf("Nhap so lieu nguoi thu %d: \n", i + 1);
    x[i] = NhDa();
  }
  return x;
}
Data** GeNDa(int n) {
  Data** x = _m(_s(Data*) * n);
  int i; for (i = 0; i < n;i++) x[i] = GeDa();
  return x;
}

int _2(Data** x, int l) {
  Data* dat[l];
  int i, j;for (i = j = 0;i < l;i++) {
    int yo = 2023 - x[i]->by;
    if (45 <= yo && yo <= 65) j++;
  }
  printf("Co %d nguoi trung  nien.\n", j);
}

void Swap(Data** x, Data** y) { Data* t = *x; *x = *y; *y = t; }
void Sorting(Data** x, int _l) {
  int i, j; for (i = 0; i < _l;i++)for (j = 0; j < _l - i - 1;j++)
    if (x[j]->bmi > x[j + 1]->bmi) Swap(x + j, x + j + 1);
}

char* GeLi(int* sp, int l) {
  int s, i, j, k;
  for (i = 0; i < l;i++) s += abs(sp[i]) + 3;
  char a[s + 2];
  for (i = j = 0; i < l;i++) {
    int b = abs(sp[i]) + 2;
    a[j++] = '+';
    for (k = 0; k < b;k++) a[j++] = '-';
  }
  a[j++] = '+'; a[j++] = '\0';
  return memcpy(_m(j), a, j);
}
void PrDa(Data* x, int* sp, int i) {
  printf("| %*d | %*s | %*d | %*.2f |", sp[0], i, sp[1], x->n, sp[2], x->by, sp[3], x->bmi);
}
void PrNDa(Data** x, int l, char** ti) {
  int sp[] = { 5,-15,15,10 }, i;
  char* a = GeLi(sp, 4);
  printf("\n%s\n", a);
  for (i = 0; i < 4; i++) printf("| %*s ", sp[i], ti[i]);
  printf("|\n%s\n", a);

  for (i = 0; i < l;i++) {
    PrDa(x[i], sp, i + 1);
    printf("\n%s\n", a);
  }
  free(a);
}
void _5() {
  printf("Nhap n khach hang: "); int n; sc("%d", &n);
  Data** x = NhNDa(n);
  char** a = _m(_s(char*));
  a[0] = "STT", a[1] = "Ten", a[2] = "Nam sinh", a[3] = "BMI";
  _2(x, n);
  printf("Nhap m khach hang: "); int m, i = 0;
  do {
    if (i++) printf("M phai nho hon N. Nhap lai: ");
    sc("%d", &m);
  } while (m > n);
  Sorting(x, n);
  printf("Danh sach m nguoi bmi tu thap den cao la: \n");
  PrNDa(x, m, a);

  for (i = 0; i < n;i++) free(x[i]);
  free(a); free(x);
}
int main() { _5(); }