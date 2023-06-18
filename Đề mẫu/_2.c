#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ff fflush(stdin)

typedef struct {
  char h[100], t[105], c[200];
  float p; int r;
} Data;

int IsVal(char* h, char* t, char* c, int r, int p) {
  int _h = strlen(h), _t = strlen(t);
  return !_h || _h > 10 || !_t || _t > 15 || r < 0 || r % 4 != 0 || p < 0;
}
Data* CrDa(char* h, char* t, char* c, int r, int p) {
  if (IsVal(h, t, c, r, p))return (Data*)-1;
  Data* dat = malloc(sizeof(Data));
  strcpy(dat->h, h);
  strcpy(dat->t, t);
  strcpy(dat->c, c);
  dat->r = r; dat->p = dat->p;
  return dat;
}
char* GetC(int x) {
  switch (x) {
  case 1: return "Exynos";
  case 2: return "SnapDragon";
  case 3: return "M1";
  case 4: return "M2";
  }
  return "";
}
Data* GeDa() {
  char t[100], h[100];
  int r, c; float p;
  do {
    r = (rand() % 10) * 4, c = 1 + rand() % 4;
    p = (float)(rand() % 1000) / 100;
    itoa(rand() % 1000, t, 16);
    itoa(rand() % 1000000, h, 16);
  } while (IsVal(h, t, GetC(c), r, p));
  return CrDa(h, t, GetC(c), r, p);
}

Data* InDa() {
  Data* dat = malloc(sizeof(Data));
  int x, i = 0;
  do {
    if (i++) printf("\nKo Hop le!\n");
    printf("Nhap hang: ");
    ff; gets(dat->h);
    printf("Nhap ten may: ");
    ff; gets(dat->t);
    printf("Nhap ram: ");
    ff; scanf("%d", &dat->r);
    printf("Nhap chip:\n1. Exynos\n2. SnapDragon\n3. M1\n4. M2\n");
    ff;scanf("%d", &x);
    strcpy(dat->c, GetC(x));
    printf("Nhap gia: ");
    ff; scanf("%f", &dat->p);
  } while (IsVal(dat->h, dat->t, dat->c, dat->r, dat->p));
  return dat;
}
Data** _1(int n) {
  Data** dat = malloc(n * sizeof(Data*));
  for (int i = 0; i < n;i++) {
    printf("\n%d.\n", i + 1);
    dat[i] = InDa();
  }
  return dat;
}
void** CPYDAT(void** x, int size) {
  void** a = malloc(size);
  return memcpy(a, x, size);
}
int main() {
  srand(time(NULL));
}