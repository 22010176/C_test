typedef struct {
  char h[10];
  int m, n;float g;
} Data;

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
