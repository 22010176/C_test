#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <math.h>

#define _p printf
#define _m malloc
#define _s sizeof
#define sc fflush(stdin);scanf
#define gs fflush(stdin);gets

typedef struct {
  char n[100], msp[100];
  int so, hsd;
} Data;

// kiem tra dau vao
void Pr(Data* a) {
  printf("%s %s %d %d\n", a->n, a->msp, a->so, a->hsd);
}
int ChDa(char n[], char msp[], int so, int hsd) {
  int _msp = strlen(msp);
  return !_msp || _msp > 4 || so < 0 || hsd < 0;
}

int CrDa(Data* a, char n[], char msp[], int so, int hsd) {
  if (ChDa(n, msp, so, hsd)) return 0;
  a->hsd = hsd; a->so = so;
  strcpy(a->n, n);
  strcpy(a->msp, msp);
  return 1;
}
int NhapDa(Data* a) {
  char n[100], msp[100];
  int so, hsd = -2, i = 0;
  while (ChDa(n, msp, so, hsd)) {
    if (i++) printf("Ko hop le!! Nhap lai.\n");
    printf("Nhap ten sp: "); gs(n);
    printf("Nhap msp: "); gs(msp);
    printf("Nhap so luong: "); sc("%d", &so);
    printf("Nhap hsd: "); sc("%d", &hsd);
  }
  return CrDa(a, n, msp, so, hsd);
}
void NhapNDa(Data x[], int n) {
  int i; for (i = 0; i < n; i++) {
    _p("Nhap may thu %d:\n", i + 1);
    NhapDa(&x[i]);
  }
}
int main() {
  int n = 3, i;
  Data a[n];
  NhapNDa(a, n);
  Sort(a, n);
  for (i = 0; i < n;i++) Pr(&a[i]);
}