#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define sc fflush(stdin);scanf
#define gs fflush(stdin);gets
#define _p printf
#define _m malloc
#define _s sizeof

typedef struct {
  char h[10];
  int m, n;float g;
} Data;
char* GeCo(int x) {
  switch (x) {
  case 1: return "Den";
  case 2: return "Do";
  case 3: return "Xanh";
  case 4: return "Trang";
  case 5: return "Vang";
  case 6: return "Bac";
  default: return "";
  }
}
int ChDa(char* h, int m, int n, float g) {
  int _h = strlen(h);
  return !_h || _h > 10 || !strlen(GeCo(m)) || n < 0 || g < 0;
}
Data* CrDa(char* h, int m, int n, float g) {
  if (ChDa(h, m, n, g))return (Data*)-2;
  Data* dat; do { dat = _m(_s(Data)); } while (!dat);
  dat->g = g; dat->n = n; dat->m = m;
  strcpy(dat->h, h);
  return dat;
}
Data* GeDa() {
  char h[10]; int m, n; float g;
  do {
    itoa(rand() % 10000, h, 16);
    m = rand() % 5 + 1, n = rand() % 100;
    g = (float)(rand() % 1000000) / 100;
  } while (ChDa(h, m, n, g));
  return CrDa(h, m, n, g);
}
Data** GeNDa(int n) {
  Data** dat = _m(_s(Data*) * (n + 1));
  int i;for (i = 0; i < n;i++) dat[i] = GeDa();
  dat[n] = (Data*)-1;
  return dat;
}

Data* InDa() {
  char h[10]; int m, n, i = 0; float g;
  do {
    if (i++) _p("Ko hop le!! Nhap lai: \n");
    _p("Nhap mau xe: "); sc("%d", &m);
    _p("Nhap hang xe: "); gs(h);
    _p("Nhap so cho ngoi (>0): "); sc("%d", &n);
    _p("Nhap gia (>0): "); sc("%f", &g);
  } while (ChDa(h, m, n, g));
  return CrDa(h, m, n, g);
}
Data** InNDa(int n) {
  Data** dat = _m(_s(Data*) * (n + 1));
  int i;for (i = 0; i < n;i++) {
    _p("Nhap xe thu %d: \n", i + 1);
    dat[i] = InDa();
  }
  dat[n] = (Data*)-1;
  return dat;
}
char* GeLi(int* x, int l) {
  int i, k, j, _l = 100;
  char* _x = _m(_l);
  for (i = j = 0; i < l;i++) {
    int a = abs(x[i]) + 2;
    _x[j++] = '+';
    for (k = 0; k < a;k++) _x[j++] = '-';
    if (strlen(_x) + x[i + 1] < _l || i >= l) continue;
    _l *= 2;
    _x = realloc(_x, _l);
  }
  _x[j++] = '+'; _x[j++] = '\0';
  return realloc(_x, j);
}
void PrDa(Data* a, int* x, int i) {
  printf("| %*d | %*s | %*s | %*d | %*.2f |\n", x[0], i, x[1], GeCo(a->m), x[2], a->h, x[3], a->n, x[4], a->g);
}
void PrNDa(Data** a, int* x, int l) {
  char* li = GeLi(x, 5);
  printf("%s\n", li);
  printf("| %*s | %*s | %*s | %*s | %*s |\n", x[0], "STT", x[1], "Mau", x[2], "Hang xe", x[3], "So cho ngoi", x[4], "Gia ban (trieu VND)");
  printf("%s\n", li);
  int i; for (i = 0; i < l;i++) {
    PrDa(a[i], x, i + 1);
    printf("%s\n", li);
  }
  printf("\n\n");
}
void Swap(Data** a, Data** b) {
  Data* t = *a;*a = *b, * b = t;
}
void Sorting(Data** a, int l) {
  int i, j;for (i = 0; i < l;i++) for (j = 0; j < l - i - 1;j++) if (a[j]->g > a[j + 1]->g) Swap(a + j, a + j + 1);
}
Data** Filter(Data** a, int l, int n, int g1, int g2) {
  Data** x = _m(_s(Data*) * (l + 1));
  int i, j; for (i = j = 0; i < l && a[i] != (Data*)-1;i++) {
    Data* z = a[i];
    if (a[i]->n >= n && g1 <= a[i]->g && a[i]->g <= g2) x[j++] = a[i];
  }
  x[j++] = (Data*)-1;
  return realloc(x, j * _s(Data*));
}
void _5() {
  printf("Nhap n: ");

  int n, s, b[] = { 5,-15,-15,15,-25 };do { sc("%d", &n); } while (n < 0);
  float a, c;
  Data** x = InNDa(n);
  printf("Bang oto: \n");
  PrNDa(x, b, n);
  printf("Sap xep theo gia: \n");
  Sorting(x, n);
  PrNDa(x, b, n);

  printf("Nhap so cho ngoi: "); sc("%d", &s);
  printf("Nhap khoang gia (a, b):"); sc("%f%f", &a, &c);
  Data** aa = Filter(x, n, s, a, c);
  _p("Danh sach oto thoa man: \n");
  PrNDa(aa, b, n);
  free(x); free(aa);
  getc(stdin);
}
int main() {
  srand(time(NULL));

  Data** x = GeNDa(100);
  int _x[] = { 5,-15,-15,15,-25 };
  Sorting(x, 100);
  PrNDa(x, _x, 10000);

}