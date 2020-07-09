#include <stdio.h>

#define    BRAK_PIERWIASTKOW                      0
#define    JEDEN_PIERWIASTEK                      1
#define	   DWA_PIERWIASTKI	                  2
#define    NIESKONCZENIE_WIELE_PIERWIASTKOW      -1


int rozwiazanie_rownania_liniowego(float a, float b, float *x) {
    int liczba_pierwiastkow;

    if (a != 0) {
        liczba_pierwiastkow = JEDEN_PIERWIASTEK;
        *x = -b/a;
    }
    else if (b != 0)
        liczba_pierwiastkow = BRAK_PIERWIASTKOW;
    else
        liczba_pierwiastkow = NIESKONCZENIE_WIELE_PIERWIASTKOW;


    return liczba_pierwiastkow;
}

int rozwiazanie_rownania_kwadratowego(float a, float b, float c, float *x1, float *x2) {
    int liczba_pierwiastkow;
    float delta;

    delta = (pow(b, 2)) - (4 * a * c);

    if (delta == 0) {
        liczba_pierwiastkow = JEDEN_PIERWIASTEK;
        *x1 = - b / (2 * a);
        /* printf("Rownanie ma 1 pierwiastek podwojny: %f\n", x1); */
    }
    else if (delta > 0) {
        liczba_pierwiastkow = DWA_PIERWIASTKI;
        *x1 = (- b - sqrt(delta)) / (2 * a);
        *x2 = (- b + sqrt(delta)) / (2 * a);
        /* printf("Rownanie ma 2 pierwiastki: %f, %f\n", x1, x2); */
    }
    else
    liczba_pierwiastkow = BRAK_PIERWIASTKOW;

    return liczba_pierwiastkow;
}


int main() {

    float a, b, c, pierwiastek1, pierwiastek2;
	int lp;	/* liczba pierwiastków */


	printf("Podaj wspolczynnik a: ");
	scanf("%f", &a);

	printf("Podaj wspolczynnik b: ");
	scanf("%f", &b);

	printf("Podaj wspolczynnik c: ");
	scanf("%f", &c);

    if (a == 0)
        lp = rozwiazanie_rownania_liniowego(b, c, &pierwiastek1);
    else
        lp = rozwiazanie_rownania_kwadratowego(a, b, c, &pierwiastek1, &pierwiastek2);


    if (lp == JEDEN_PIERWIASTEK)
		printf("Rownanie kwadratowe ma jeden pierwiastek: %f\n", pierwiastek1);
	else if (lp == BRAK_PIERWIASTKOW)
		printf("Rownanie nie posiada zadnych pierwiastkow.");
	else
		printf("Wystepuja dwa pierwiastki: %f, %f\n", pierwiastek1, pierwiastek2);

	return 0;
}
