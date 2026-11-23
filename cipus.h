#ifndef CIPUS_H
#define CIPUS_H

#define MAX 20

int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k);
int utworz_macierz(double M[][MAX], int w, int k);

#endif