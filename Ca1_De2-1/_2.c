#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <time.h>

#define _M malloc
#define _R realloc
#define _P printf
#define sc fflush(stdin);scanf
#define gs fflush(stdin);gets
#define _L strlen
#define _S sizeof

typedef struct {
  char m[11], dc[31];
  int nv, ds;
} Data;

int ChM(char* m) {
  int i; for (i = 0; i < _L(m);i++) if (!isdigit(m[i])) return 0;
  return 1;
}
int ChDa(char* m, char* dc, int nv, int ds) {
  int _m = _L(m), _dc = _L(dc);
  return _m && _m <= 30 && ChM(m) && _dc && _dc <= 10 && nv > 0 && ds >= 0;
}
Data* CrDa(char* m, char* dc, int nv, int ds) {
  if (!ChDa(m, dc, nv, ds)) return (Data*)-2;
  Data* dat;
  do { dat = _M(_S(Data)); } while (!dat);
  strcpy(dat->dc, dc);
  strcpy(dat->m, m);
  dat->nv = nv; dat->ds = ds;
  return dat;
}
Data* GeDa() {
  char m[11], dc[31]; int nv, ds;
  do {
    itoa(rand(), m, 8);
    itoa(rand(), dc, 8);
    nv = rand() % 1000, ds = rand() % 1000;
  } while (!ChDa(m, dc, nv, ds));
  return CrDa(m, dc, nv, ds);
}
Data** GeNDa(int n) {
  Data** dat = _M(_S(Data*) * (n + 1));
  int i; for (i = 0; i <= n;i++) dat[i] = i < n ? GeDa() : (Data*)-1;
  return dat;
}
Data* NhDa() {
  char m[11] = "", dc[31]; int nv, ds, i = 0;
  do {
    printf("Nhap ma: "); gs(m);
  } while (!ChM(m) || !_L(m));
  do {
    if (i++) printf("Ko hop le! Nhap lai: \n");
    printf("Nhap nv (>0): "); sc("%d", &nv);
    printf("Nhap dia chi: "); gs(dc);
    printf("Nhap doanh so (>=0): "); sc("%d", &ds);
  } while (!ChDa(m, dc, nv, ds));
  return CrDa(m, dc, nv, ds);
}
Data** NhNDa(int n) {
  Data** dat = _M(_S(Data*) * (n + 1));
  int i; for (i = 0; i <= n;i++) {
    printf("\nNhap may thu %d: \n", i + 1);
    dat[i] = i < n ? NhDa() : (Data*)-1;
  }
  return dat;
}

char* GeLi(int* sp, int _l) {
  int s, i, j, k;
  for (i = s = 0; i < _l;i++) s += abs(sp[i]) + 3;
  char a[s + 2];
  for (i = j = 0; i < _l;i++) {
    int len = abs(sp[i]) + 2;
    a[j++] = '+';
    for (k = 0; k < len;k++) a[j++] = '-';
  }
  a[j++] = '+'; a[j++] = '\0';
  return memcpy(_M(j), a, j);
}

void PrDa(Data* x, int* n, int i) {
  if (x == (Data*)-2) return;
  _P("| %*d | %*s | %*d | %*d | %*s |", n[0], i, n[1], x->m, n[2], x->nv, n[3], x->ds, n[4], x->dc);
}
void PrNDa(Data** x, int _l, char** ti) {
  int sp[] = { 5,10,15,15,15 }, i;
  char* a = GeLi(sp, 5);
  _P("\n%s\n", a);
  for (i = 0; i < 5;i++) _P("| %*s ", sp[i], ti[i]);
  _P("|\n%s\n", a);
  for (i = 0; i < _l;i++) {
    PrDa(x[i], sp, i + 1);
    _P("\n%s\n", a);
  }
  free(a);
}
void Swap(Data** a, Data** b) { Data* t = *a; *a = *b; *b = t; }
void Sorting(Data** x, int l) {
  int i, j;for (i = 0; i < l;i++) for (j = 0; j < l - 1 - i;j++)
    if (x[j]->ds > x[j + 1]->ds) Swap(x + j, x + j + 1);
}
void _5() {
  _P("Nhap n: "); int n; sc("%d", &n);
  char** a = _M(_S(char*) * 5);
  a[0] = "STT", a[1] = "MaCH", a[2] = "So nhan vien", a[3] = "Doanh so", a[4] = "Dia chi";
  Data** x = NhNDa(n);
  _P("Bang san pham vua nhap: \n");
  PrNDa(x, n, a);
  Sorting(x, n);
  _P("Sau khi sap xep theo doanh so: \n");
  PrNDa(x, n, a);

  int i; for (i = 0; i < n;i++) free(x[i]);
  free(a); free(x);
}
int main() { _5(); }

