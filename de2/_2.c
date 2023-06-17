#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

typedef struct { char ten[100]; int soluong; char size[5]; float gia; } Fuku;
Fuku** _A(int _n) {
  Fuku** chochua = malloc(_n * sizeof(Fuku**));
  int i, soluong, _size; float gia = 0; char ten[100], size[100];
  for (i = 0; i < _n;i++) {
    printf("\nNhap ao %d\n", i + 1);
    // Nhap, check ten
    do {
      printf("Nhap ten: ");
      fflush(stdin);
      gets(ten);
    } while (strlen(ten) > 10);
    // Nhap, check so luong
    do {
      // nhap
      printf("Nhap so luong: ");
      fflush(stdin);
      scanf("%d", &soluong);
      //check
      if (soluong >= 0) break;
    } while (1);
    // Nhap, check size
    while (1) {
      printf("Nhap size: ");
      // nhap
      fflush(stdin);
      scanf("%d", &_size);
      switch (_size) {
      case 1:
        strcpy(size, "S");
        break;
      case 2:
        strcpy(size, "M");
        break;
      case 3:
        strcpy(size, "L");
        break;
      case 4:
        strcpy(size, "XL");
        break;
      case 5:
        strcpy(size, "2XL");
        break;
      }
      // check
      if (0 < _size && _size < 6)  break;
    }
    do {
      printf("Nhap gia: ");
      // nhap
      fflush(stdin);
      scanf("%f", &gia);
      // check
    } while (gia <= 0);


    // Them vao cho chua
    Fuku* A = malloc(sizeof(Fuku));
    strcpy(A->ten, ten);
    strcpy(A->size, size);
    A->gia = gia;
    A->soluong = soluong;
    chochua[i] = A;
  }
  return chochua;
}

int main() {
  int _n = 3;
  Fuku** A = _A(_n);
  for (int i = 0; i < _n;i++) {
    printf("\n%d.\nTen: %s\n", i + 1, A[i]->ten);
    printf("So Luong: %d\n", A[i]->soluong);
    printf("gia: %.2lf\n", A[i]->gia);
    printf("Size: %s\n", A[i]->size);
    printf("\n");
  }
}