#include "cipus.h"
#include "matrix.h"
#include <stdio.h>

int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k) {
  int i, j;
  FILE *f;
  f = fopen(nazwa, "r");

  if (f == NULL) {
    printf("Blad: nie mozna otworzyc pliku\n");
    return 1;
  }
  if (fscanf(f, "%d %d", w, k) != 2) {
    printf("Blad: brak wymiarow\n");
    fclose(f);
    return 1;
  }

  printf("Wymiary: %d x %d\n", *w, *k);

  if (!wymiary_poprawne(*w, *k)) {
    printf("Blad: niepoprawne wymiary\n");
    fclose(f);
    return 1;
  }

  for (i = 0; i < *w; i++) {
    for (j = 0; j < *k; j++) {
      if (fscanf(f, "%lf", &M[i][j]) != 1) {
        printf("Blad: brak elementu [%d][%d]\n", i, j);
        fclose(f);
        return 1;
      }
    }
  }

  fclose(f);
  return 0;
}

int zapisz_macierz(FILE *f, double M[][MAX], int w, int k) {
  int i, j;

  if (fprintf(f, "%d %d\n", w, k) < 0) {
    return 1;
  }
  for (i = 0; i < w; i++) {
    for (j = 0; j < k; j++) {
      if (fprintf(f, "%.3g%c", M[i][j], j + 1 == k ? '\n' : ' ') < 0) {
        return 1;
      }
    }
  }
  return 0;
}

int utworz_macierz(double M[][MAX], int w, int k) {
  int wynik;
  FILE *f = fopen("wynik.txt", "w");

  if (f == NULL) {
    fprintf(stderr, "Blad: nie mozna utworzyc pliku wynik.txt\n");
    return 1;
  }

  wynik = zapisz_macierz(f, M, w, k);

  if (fclose(f) != 0) {
    wynik = 1;
  }

  if (wynik != 0) {
    fprintf(stderr,
            "Blad: nie udalo sie zapisac macierzy do pliku wynik.txt\n");
    return 1;
  }

  return 0;
}