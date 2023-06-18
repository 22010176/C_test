#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

typedef struct {
  char t[100], s[100];
  int s; float x;
} Data;
int CheckData(char* t, char* s, int n, float s2) {
  int _t = strlen(t), _s = strlen(s);
  return !_t || t > 10 || !_s || _s > 5 || n < 0 || s2 < 0;
}
Data* CrDa(char* t, char* s, int n, float s2) {
  Data* dat = malloc(sizeof(Data));

}
int main() {

}