#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

#define MAX 20

void wypisz(double M[][MAX], int w, int l);
int wymiary_poprawne(int w, int k);

void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);
void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);
void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA,
            int kB);

int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k);
int zapisz_macierz(FILE *f, double M[][MAX], int w, int k);

#endif