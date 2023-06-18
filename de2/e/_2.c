#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
//     &a a
#define ff fflush(stdin)
#define P printf
#define len strlen
#define gs gets

typedef struct {
  int n; float p;
  char t[100], s[100];
} Data;
// B
void PD(Data* d, int i, int* a) {
  if (d == (Data*)-1) printf("\nNo");
  else printf("\n| %*d | %*s | %*d | %*s | %*.2f |", a[0], i, a[1], d->t, a[2], d->n, a[3], d->s, a[4], d->p);
}
char* PR(int* d, int l) {
  int j = 0, n = 20;
  char* x = malloc(n * sizeof(char));
  int _i, _j;for (_i = 0; _i < l;_i++) {
    x[j++] = '+';
    for (_j = 0; _j < abs(d[_i]) + 2;_j++) {
      if (j == n) {
        n *= 2;
        x = realloc(x, n * sizeof(char));
      }
      x[j++] = '-';
    }
  }
  x[j++] = '+'; x[j++] = '\0';
  return realloc(x, j * sizeof(char));
}
void PND(Data** d, int n) {
  int* cols = malloc(5 * sizeof(int)), i;
  cols[0] = 3; cols[1] = -20;
  cols[2] = 10; cols[3] = -10; cols[4] = -15;
  char* a = PR(cols, 5);
  printf("\n%s", a);
  printf("\n| %*s | %*s | %*s | %*s | %*s |", cols[0], "STT", cols[1], "Ten san pham", cols[2], "So luong", cols[3], "Size", cols[4], "Gia ban (k VND)");
  for (i = 0; i < n && d[i] != (Data*)-1;i++) {
    P("\n%s", a);
    PD(d[i], i + 1, cols);
  }
  P("\n%s", a);
  free(cols);
}
Data** CRAD(int n) { return malloc(n * sizeof(Data*)); }
// A
char* GetS(int x) {
  switch (x) {
  case 1: return "S";
  case 2: return "M";
  case 3: return "L";
  case 4: return "XL";
  case 5: return "2XL";
  default: return "";
  }
}
int IsVa(char* t, char* s, int n, int p) {
  int l = len(t), ls = len(s);
  return !l || l > 10 || !ls || ls > 3 || n < 0 || p < 0;
}
Data* CrDa(char* t, char* s, int n, int p) {
  if (IsVa(t, s, n, p)) return (Data*)-1;
  Data* _d = malloc(sizeof(Data));
  _d->n = n; _d->p = p;
  strcpy(_d->s, s);
  strcpy(_d->t, t);
  return _d;
}
Data* NhDa() {
  char t[100];
  int n, _s, i = 0; float p;
  do {
    if (i++) printf("Ko hop le!!!\n\n");
    P("Nhap ten: "); ff; gets(t);
    P("Nhap size (1-5): "); ff; scanf("%d", &_s);
    P("Nhap soluong/gia: "); ff; scanf("%d%f", &n, &p);
  } while (IsVa(t, GetS(_s), n, p));
  return CrDa(t, GetS(_s), n, p);
}
Data** NhNDa(int n) {
  Data** x = CRAD(n);
  int i; for (i = 0; i < n;i++) {
    printf("\nNhap san pham %d: \n", i + 1);
    x[i] = NhDa();
  }
  return x;
}

Data* RDa(int i) {
  Data* a = malloc(sizeof(Data));
  char _a[100];
  strcpy(a->t, itoa(i, _a, 16));
  strcpy(a->s, GetS(rand() % 5 + 1));
  a->n = rand() % 10000; a->p = (float)(rand() % 1000000) / 100;
  return a;
}
// C
void Swap(void** _a, void** _b) {
  void* temp = *_a;
  *_a = *_b; *_b = temp;
}
void Sorting(void** _a, int _l, int (*_f)(void*, void*)) {
  int i, j;for (i = 0; i < _l;i++) for (j = 0; j < _l - i - 1;j++)
    if (_f(_a[j], _a[j + 1])) Swap(_a + j, _a + j + 1);
}
int C_1(void* a, void* b) { return ((Data*)a)->n < ((Data*)b)->n; }
float C_2(Data** A, int l) { // Tinh Tong luong tien  
  float x = 0;
  int i; for (i = 0; i < l; i++) x += (A[i]->p);
  return x;
}
//  &D = a -> D = (*a)

int D_1(Data* a, float x, float y, char* s) {
  float p = a->p;
  return x <= p && p <= y && !strcmp(a->s, s);
}
Data** Filter(Data** A, int l, int x, int y, char* s) {
  Data** _d = CRAD(l); int j = 0, i;
  for (i = 0; i < l;i++) if (D_1(A[i], x, y, s)) _d[j++] = A[i];
  _d[j++] = (Data*)-1;
  return realloc(_d, j * sizeof(Data*));
}
int main() {

  for (int i = 0; i < 200;i++) {
    printf("%d %c\n", i, i);

  }
  // srand(time(NULL));
  // int n = 20, i;
  // Data** A = CRAD(n);
  // for (i = 0; i < n;i++) A[i] = RDa(i);
  // Sorting((void**)A, n, C_1);
  // Data** B = Filter(A, n, 0, 10000, "M");
  // PND(A, n);
  // free(A); free(B);
};