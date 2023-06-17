#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct {
  int seat; double price;
  char branch[10], color[5];
} Xe;

int checkInt(int x) { return x > 0; }
int checkDouble(double x) { return x > 0; }
Xe* TaoXe(char* hang, char* mau, int seat, double gia) {
  Xe* _xe = malloc(sizeof(Xe));
  strcpy(_xe->branch, hang);
  strcpy(_xe->color, mau);
  _xe->seat = seat; _xe->price = gia;
  return _xe;
}
Xe* CopyXe(Xe _a) { return TaoXe(_a.branch, _a.color, _a.seat, _a.price); }
Xe* NhapXe() {
  char hang[10], _mau[6];
  int seat, mau; double gia;
  do {
    printf("Nhap hang xe: ");
    fflush(stdin); gets(hang);
  } while (strlen(hang) >= 10);

  do {
    printf("Nhap mau xe (1-6): ");
    fflush(stdin);
    scanf("%d", &mau);
    switch (mau) {
    case 1:
      strcpy(_mau, "Den");
      break;
    case 2:
      strcpy(_mau, "Do");
      break;
    case 3:
      strcpy(_mau, "Xanh");
      break;
    case 4:
      strcpy(_mau, "Trang");
      break;
    case 5:
      strcpy(_mau, "Vang");
      break;
    case 6:
      strcpy(_mau, "Bac");
      break;
    }
  } while (mau > 6 || mau < 0);

  do {
    printf("Nhap cho ngoi xe (>0): ");
    fflush(stdin);
    scanf("%d", &seat);
  } while (seat < 0);

  do {
    printf("Nhap gia xe (>0): ");
    fflush(stdin);
    scanf("%lf", &gia);
  } while (gia < 0);

  return TaoXe(hang, _mau, seat, gia);
}
void InXe(Xe* _a) {
  printf("\nHang: %s\nMau: %s\nCho Ngoi: %d\nGia: %lf\n", _a->branch, _a->color, _a->seat, _a->price);
}
void printLine(int time) {
  printf("+");
  int i;for (i = 0; i < time;i++) printf("-");
}
void printRow() {

}
void PrintTable(char** _cols, int cols, void** Item, int num, void (*f)(void**, int)) {
  int* size = malloc(4 * cols), i;
  for (i = 0; i < cols;i++) {
    size[i] = strlen(_cols[i]) + 2;
    printLine(size[i]);
  }

}
int main() {
  char* a = malloc(10);
  strcpy(a, "asdf");
  printf("%s", a);
  InXe(NhapXe());
}