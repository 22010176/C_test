#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
typedef struct {
  int seat;
  double price;
  char* branch, * color;
} Xe;
char* NhapMauXe(int x) {
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
int checkInt(int x) { return x > 0; }
int checkDouble(double x) { return x > 0; }
Xe* TaoXe(char* hang, char* mau, int seat, double gia) {
  Xe* _xe = malloc(sizeof(Xe));
  strcpy(_xe->branch, hang);
  strcpy(_xe->color, mau);
  _xe->seat = seat;
  _xe->price = gia;
  return _xe;
}
Xe* CopyXe(Xe _a) { return TaoXe(_a.branch, _a.color, _a.seat, _a.price); }
Xe* NhapXe() {
  char* hang = malloc(11 * sizeof(char));
  char* _mau = malloc(6 * sizeof(char));
  int seat, mau;
  double a;
  do {
    printf("Nhap hang xe: ");
    fflush(stdin); gets(hang);
  } while (strlen(hang) >= 10);
  do {
    printf("Nhap mau xe(1-6): ");
    fflush(stdin); scanf("%d", mau);
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
    printf("Nhap cho ngoi xe (>0): ");
    fflush(stdin);
    scanf("%d", &seat);
  } while (seat < 0);

  do {
    printf("Nhap gia xe (>0): ");
    fflush(stdin);
    scanf("%lf", &a);
  } while (a < 0);

  return TaoXe(hang, _mau, seat, a);
}
void InXe(Xe* _a) {
  printf("%s %s %d %lf", _a->branch, _a->color, _a->seat, _a->price);
}
int main() {
  char* a = malloc(10);
  strcpy(a, "asdf");
  printf("%s", a);
  InXe(NhapXe());
}