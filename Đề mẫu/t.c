typedef struct {
  char h[10], t[15];
  int r, c; float g;
} Data;

// generate data
Data* GeDa() {
  char h[100], t[150];
  int r, c; float g;
  do {
    itoa(rand() % 10000, h, 16);
    itoa(rand() % 10000, t, 15);
    r = (rand() % 100) * 4, c = rand() % 4 + 1;
    g = (rand() % 100000) / 100;
  } while (ChDa(h, t, r, c, g));
  return CrDa(h, t, r, c, g);
}
// generate n data
Data** GeNDa(int n) {
  Data** dat = _m(_s(Data*) * (n + 1));
  int i; for (i = 0; i < n;i++) dat[i] = GeDa();
  dat[n] = (Data*)-1;
  return dat;
}