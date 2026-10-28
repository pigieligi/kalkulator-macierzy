#include <stdio.h>
#define MAX 20

void wypisz(double M[][MAX], int w, int l)
{
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < l; j++) {
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
}

int wymiary_poprawne(int w, int k)
{
    return (w >= 1 && w <= MAX && k >= 1 && k <= MAX);
}

int zgodne_do_sumy(int wA, int kA, int wB, int kB);

void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k)
{
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k)
{
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int wB, int kB)
{
    int i, j, n;
    double suma;
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            suma = 0.0;
            for (n = 0; n < kA; n++) {
                suma = suma +A[i][n] * B[n][j];
            }
            C[i][j] = suma;
        }
    }
}

int main(void) {

int i, j;
int wA = 2, kA = 3, wB = 2, kB = 3;
double A[MAX][MAX] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
double B[MAX][MAX] = {{7.0, 8.0, 9.0}, {10.0, 11.0, 12.0}};
double C[MAX][MAX] = {{MAX}, {MAX}};

wypisz(A, wA, kA);
wypisz(B, wB, kB);
wypisz(C, wA, kA);

printf("Suma A + B\n");
dodaj(A, B, C, wA, kA);
wypisz(C, wA, kA);

printf("Roznica A - B\n");
odejmij(A, B, C, wA, kA);
wypisz(C, wA, kA);

printf("Iloczyn A * B\n");
pomnoz(A, B, C, wA, kA, wB, kB);
wypisz(C, wA, kB);
return 0;

}


