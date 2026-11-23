#include "cipus.h"
#include "matrix.h"
#include <stdio.h>

int main(void) {
  double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  int wA, kA, wB, kB, wC, kC, op;

  if (wczytaj_macierz("cipsa.txt", A, &wA, &kA) != 0) {
    printf("Blad: nie mozna wczytac macierzy A\n");
    return 1;
  }

  if (wczytaj_macierz("cipsem.txt", B, &wB, &kB) != 0) {
    printf("Blad: nie mozna wczytac macierzy B\n");
    return 1;
  }

  printf("Operacja: 1 - dodawanie, 2 - odejmowanie, 3 - mnozenie\n");

  if (scanf("%d", &op) != 1) {
    fprintf(stderr, "Wpisz numer operacji jako liczbe.\n");
    return 1;
  }

  if (op == 1 || op == 2) {
    if (wA != wB || kA != kB) {
      fprintf(
          stderr,
          "Do dodawania i odejmwoania macierze musza miec te same wymiary.\n");
      return 1;
    }

    if (op == 1) {
      dodaj(A, B, C, wA, kA);
    } else {
      odejmij(A, B, C, wA, kA);
    }

    wC = wA;
    kC = kA;
  } else if (op == 3) {
    if (kA != wB) {
      fprintf(stderr, "Liczba kolumn A musi byc rowna liczbie wierszy B.\n");
      return 1;
    }

    pomnoz(A, B, C, wA, kA, kB);
    wC = wA;
    kC = kB;
  } else {
    fprintf(stderr, "Wybierz 1, 2 lub 3.\n");
    return 1;
  }

  if (utworz_macierz(C, wC, kC) != 0) {
    return 1;
  }

  printf("Wynik zapisano do pliku wynik.txt\n");

  return 0;
}