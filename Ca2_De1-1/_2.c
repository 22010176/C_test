#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <conio.h>

#define _s sizeof
#define _m malloc
#define re realloc
#define pr printf
#define sc fflush(stdin); scanf
#define gs fflush(stdin); gets
#define _l strlen

typedef struct { char id[5], n[31];  int tv, di; } Data;
int ChId(char* id) {
  int i; if (_l(id) != 4) return 1;

  for (i = 0; i < _l(id);i++) if (!isdigit(id[i])) return 1;
  return 0;
}
int ChDa(char* id, char* n, int tv, int d) { return !_l(n) || _l(n) > 30 || ChId(id) || tv <= 0 || d < 0; }
Data* CrDa(char* id, char* n, int tv, int d) {
  if (ChDa(id, n, tv, d)) return (Data*)-2;
  Data* dat = _m(_s(Data));
  strcpy(dat->id, id); strcpy(dat->n, n);
  dat->tv = tv; dat->di = d;
  return dat;
}
Data* GeDa() {
  char id[100], n[100];
  int tv, d, x;
  do {
    itoa(rand() % 9000 + 1000, id, 10);
    itoa(rand(), n, 16);
    tv = rand() % 100, d = rand() % 100 + 10;
  } while (ChDa(id, n, tv, d));
  return CrDa(id, n, tv, d);
}
Data** GeNDa(int n) {
  Data** x = _m(_s(Data*) * (n + 1));
  int i; for (i = 0; i <= n;i++) x[i] = i != n ? GeDa() : (Data*)-1;
  return x;
}
Data* NhDa() {
  char id[4], n[30], tv[10], di[10];
  int _id = 0, _ch = 0;

  pr("Nhap ma CH(4 chu so): ");
  do {
    if (_id++) pr("ID ko hop le, nhap lai id: ");
    gs(id);
  } while (ChId(id));
  do {
    if (_ch++) pr("Ko hop le, nhap lai thong tin: \n");
    pr("Nhap ten: "); gs(n);
    pr("Nhap so thanh vien: "); gs(tv);
    pr("Nhap so dien: "); gs(di);
  } while (ChDa("1234", n, atoi(tv), atoi(di)));
  return CrDa(id, n, atoi(tv), atoi(di));
}
Data** NhNDa(int n) {
  Data** dat = _m(_s(Data*) * (n + 1));
  int i; for (i = 0; i <= n;i++) {
    if (i < n)pr("\n\nNhap can ho thu %d:\n", i + 1);
    dat[i] = NhDa();
  }
  dat[n] = (Data*)-1;
  return dat;
}
char* GeLi(char* s, int* x, int l) {
  int i, j, k, len = 100, sum = 0;
  for (i = 0; i < l;i++) sum += abs(x[i]) + 3;
  for (i = j = 0; i < l;i++) {
    int a = abs(x[i]) + 2;
    s[j++] = '+';
    for (k = 0; k < a;k++) s[j++] = '-';
  }
  s[j++] = '+'; s[j++] = '\0';
}
void PrDa(Data* x, int* s, int i) { pr("| %*d | %*s | %*s | %*d | %*d |", s[0], i, s[1], x->id, s[2], x->n, s[3], x->tv, s[4], x->di); };
void PrNDa(Data** x, char s[][100], int l) {
  int i, j, sp[] = { 5,10,15,15,10 };
  char li[1000]; GeLi(li, sp, 5);
  pr("\n%s\n", li);
  for (i = 0; i < l;i++) pr("| %*s ", sp[i], s[i]);
  pr("|\n%s\n", li);

  for (i = 0; x[i] != (Data*)-1;i++) {
    PrDa(x[i], sp, i + 1);
    pr("\n%s\n", li);
  }
}
void Swap(Data** x, Data** y) { Data* t = *x; *x = *y; *y = t; }
void Sorting(Data** x, int l) {
  int i, j;
  for (i = 0; i < l; i++) for (j = 0; j < l - i - 1; j++)
    if (strcmp(x[j]->id, x[j + 1]->id) > 0) Swap(x + j, x + j + 1);
}
void _5() {
  pr("Nhap n: "); int n; sc("%d", &n);
  Data** x = NhNDa(n);
  char a[][100] = { "STT","MaCH","Ten chu ho","So thanh vien","So dien" };
  pr("Danh sach can ho vua nhap: \n");
  PrNDa(x, a, 5);
  pr("Danh sach can ho sap xep theo id: \n");
  Sorting(x, n);
  PrNDa(x, a, 5);
};
int main() { _5(); }
