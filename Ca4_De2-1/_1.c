#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int** _1(int m, int n) {
  int i, j, ** A = 0;
  do { A = malloc((m + 1) * sizeof(int**)); } while (!A);
  for (i = 0; i < m;i++) {
    A[i] = malloc((n + 1) * sizeof(int));
    for (j = 0; j < n;j++) {
      printf("Nhap phan tu A[%d][%d]: ", i, j);
      fflush(stdin);scanf("%d", &A[i][j]);
    }
    A[i][n] = -1;
  }
  A[m] = (int*)-1;
  return A;
}
int ChPr(int x) {
  int i, j;
  if (x % 2 == 0) return 0;
  for (i = 3; i < x / 2 + 1;i += 2) if (x % i == 0) return 0;
  return 1;
}
void** _2(int** x, int m, int n) {
  int i, j, k;
  for (i = 0; i < m;i++) for (j = 0; j < n;j++)
    if (ChPr(x[i][j])) {
      k++;
      printf("i:%d j:%d x = %d\n", i, j, x[i][j]);
    }
  if (!k) printf("\nMang 2 chieu ko co so nguyen to nao.");
}

void _3(int** x, int m, int n) {
  int i, j;
  for (i = 0; i < m;i++) {
    for (j = 0; j < n;j++) printf("%5d ", x[i][j]);
    printf("\n");
  }
  printf("\n");
}
void _4() {
  int m, n;
  do { printf("Nhap m (<10): ");scanf("%d", &m); } while (m > 10);
  do { printf("Nhap n (<10): ");scanf("%d", &n); } while (n > 10);
  int** x = _1(m, n);
  _3(x, m, n); _2(x, m, n);
}
int main() {
  _4();
}